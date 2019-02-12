#ifndef VITAMATERIALKIT_UTILSTWITTER_HH
#define VITAMATERIALKIT_UTILSTWITTER_HH

#include <malloc.h>

#include <psp2/tw_dialog.h>
#include <psp2/sysmodule.h>
#include <psp2/net/netctl.h>
#include <psp2/net/http.h>
#include <psp2/apputil.h>
#include <psp2/libssl.h>
#include <psp2/display.h>

#include <vita2d.h>

class UtilsTwitter {
private:
    SceCommonDialogStatus status;
    int result;

    void initTwitter();
    void terminateTwitter();
    void initTwitterDialog();

public:
    int getResult() const;

public:
    void renderTwitterDialog();

};


#endif //VITAMATERIALKIT_UTILSTWITTER_HH
