#include "UtilsTwitter.hh"

void UtilsTwitter::initTwitter() {
    SceAppUtilInitParam		initParam;
    SceAppUtilBootParam		bootParam;

    memset(&initParam, 0 ,sizeof(SceAppUtilInitParam));
    memset(&bootParam, 0 ,sizeof(SceAppUtilBootParam));
    sceAppUtilInit(&initParam, &bootParam);

    sceSysmoduleLoadModule(SCE_SYSMODULE_NET);
    sceSysmoduleLoadModule(SCE_SYSMODULE_HTTPS);
    sceSysmoduleLoadModule(SCE_SYSMODULE_NP);

    sceAppUtilPhotoMount();

    SceNetInitParam param;
    int size = 16 * 1024;
    param.memory = malloc((size_t) size);
    param.size = size;
    param.flags = 0;
    sceNetInit(&param);

    sceNetCtlInit();
    sceHttpInit(512 * 1024);
    sceSslInit(300 * 1024);

}

void UtilsTwitter::terminateTwitter() {
    sceSslTerm();
    sceHttpTerm();
    sceNetCtlTerm();
    sceNetTerm();

    sceAppUtilPhotoUmount();

    sceSysmoduleUnloadModule(SCE_SYSMODULE_NP);
    sceSysmoduleUnloadModule(SCE_SYSMODULE_HTTPS);
    sceSysmoduleUnloadModule(SCE_SYSMODULE_NET);

    sceAppUtilShutdown();
}

void UtilsTwitter::initTwitterDialog() {
    SceTwDialogParam twDialogParam;
    SceTwDialogSpecParam twDialogSpecParam;

    // initalize parameter of twitter dialog
    sceTwDialogParamInit(&twDialogParam);
    sceTwDialogSpecParamInit(&twDialogSpecParam);
    twDialogParam.twDialogSpecParam = &twDialogSpecParam;

    // set parameter of twitter dialog
    twDialogParam.mode = SCE_TW_DIALOG_MODE_ACCOUNT;
    twDialogParam.twDialogSpecParam->tweetMsgStr = (SceChar8 *) "hello world";// UTF-8

    sceTwDialogInit(&twDialogParam);
}

void UtilsTwitter::renderTwitterDialog() {
    this->initTwitter();

    bool shownDial = false;
    int run = 1;
    SceTwDialogResult	pidResult;

    while (run) {
        vita2d_start_drawing();
        vita2d_clear_screen();

        if (!shownDial) {
            this->initTwitterDialog();
            shownDial = true;
        }

        status = sceTwDialogGetStatus();

        if (status == SCE_COMMON_DIALOG_STATUS_FINISHED) {
            SceCommonDialogUpdateParam	updateParam;
            memset(&updateParam, 0, sizeof(updateParam));
            sceCommonDialogUpdate(&updateParam);



            sceTwDialogTerm();
            shownDial = false;
            run = 0;
        }


        vita2d_end_drawing();
        vita2d_common_dialog_update();
        vita2d_swap_buffers();
        sceDisplayWaitVblankStart();
    }

    sceClibMemset( &pidResult, 0x0, sizeof(SceTwDialogResult) );
    result = sceTwDialogGetResult(&pidResult);


    this->terminateTwitter();
}

int UtilsTwitter::getResult() const {
    return result;
}
