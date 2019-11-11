#ifndef VITA_MATERIAL_KIT_IME_HH
#define VITA_MATERIAL_KIT_IME_HH

#include <stdio.h>
#include <string>
#include <map>
#include <locale>
#include <codecvt>
#include <string.h>
#include <stdbool.h>

#include <vita2d.h>
#include <psp2/appmgr.h>
#include <psp2/apputil.h>
#include <psp2/types.h>
#include <psp2/kernel/processmgr.h>
#include <psp2/message_dialog.h>
#include <psp2/ime_dialog.h>
#include <psp2/display.h>
#include <psp2/gxm.h>
#include <psp2/kernel/sysmem.h>

typedef struct IMEData {
    std::basic_string<char16_t> title;
    std::basic_string<char16_t> initialText;
    unsigned int type;
    SceUInt32 maxTextLength;
    unsigned int option;
    std::string result;
} IMEData;


class UtilsIME{
private:
	int i;
    bool show_ime;
    std::string current_id;
	SceCommonDialogStatus status;
    std::map<std::string, IMEData> datas;
    std::string input_text_buffer_utf8;
    SceWChar16 *input_text_buffer_utf16 = nullptr;

	void initImeDialog();

	public:
		UtilsIME();

		void prepare(std::string id, std::string title = "", std::string initialText = "", unsigned int type = SCE_IME_TYPE_BASIC_LATIN, SceUInt32 maxTextLength = SCE_IME_DIALOG_MAX_TITLE_LENGTH, unsigned int option = 0);
		void start(std::string id);

        std::string getResult(std::string id);
		SceCommonDialogStatus getStatus() const;

        void controller();

};

#endif

