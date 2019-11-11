#include <utility>

#include "UtilsIME.hh"
#include "../core/App.hh"

UtilsIME::UtilsIME(){
}

void UtilsIME::prepare(std::string id, std::string title, std::string initialText, unsigned int type, SceUInt32 maxTextLength, unsigned int option) {
    IMEData data;
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> converter;

    data.title = converter.from_bytes(title);
    data.initialText = converter.from_bytes(initialText);
    data.type = type;
    data.maxTextLength = maxTextLength;
    data.option = option;

    datas[id] = data;
}

void UtilsIME::start(std::string id) {
    App::disableViewContents = true;
    current_id = std::move(id);
    initImeDialog();
}

void UtilsIME::initImeDialog() {
    // Convert UTF8 to UTF16
    delete input_text_buffer_utf16;
    input_text_buffer_utf16 = new SceWChar16[datas[current_id].maxTextLength + 1];

    SceImeDialogParam param;
    sceImeDialogParamInit(&param);

    param.sdkVersion = 0x03150021,
    param.supportedLanguages = 0x0001FFFF;
    param.languagesForced = SCE_TRUE;
	param.type = datas[current_id].type;
	param.option = datas[current_id].option;
	if (datas[current_id].option == SCE_IME_OPTION_MULTILINE)
		param.dialogMode = SCE_IME_DIALOG_DIALOG_MODE_WITH_CANCEL;
	param.title = (const SceWChar16 *) datas[current_id].title.c_str();
	param.maxTextLength = datas[current_id].maxTextLength;
    param.inputMethod = 0;
    param.initialText = (SceWChar16 *) datas[current_id].initialText.c_str();
    param.inputTextBuffer = input_text_buffer_utf16;

	sceImeDialogInit(&param);
    show_ime = true;
}

void UtilsIME::controller() {
    if (show_ime) {
        status = sceImeDialogGetStatus();

        if (status == SCE_COMMON_DIALOG_STATUS_FINISHED) {
            SceImeDialogResult result={};
            sceImeDialogGetResult(&result);

            if (result.button == SCE_IME_DIALOG_BUTTON_CLOSE)
                status = SCE_COMMON_DIALOG_STATUS_FINISHED;
            else {
                std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> converter;
                input_text_buffer_utf8 = converter.to_bytes((char16_t*) input_text_buffer_utf16);
                datas[current_id].result = std::string(input_text_buffer_utf8);
            }

            sceImeDialogTerm();
            App::disableViewContents = false;
            current_id = "";

            show_ime = false;
        }
    }
}


SceCommonDialogStatus UtilsIME::getStatus() const {
    return status;
}

std::string UtilsIME::getResult(std::string id) {
    return datas[id].result;
}
