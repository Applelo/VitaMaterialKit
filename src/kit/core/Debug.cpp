#include "Debug.hh"

int g_log_fd = -1;

int log_init() {

    if (DEBUG_APP == 1 && DEBUG_NET == 1) {
        debugNetInit(DEBUG_NET_IP, DEBUG_NET_PORT, 3);
    }

    if (DEBUG_APP == 1 && DEBUG_LOG == 1) {
        sceIoMkdir(DEBUG_LOG_DIR, 0777);

        SceDateTime logTime;
        memset(&logTime, 0, sizeof(logTime));

        sceRtcGetCurrentClockLocalTime(&logTime);

        char formattedTime[40] = { 0 };
        snprintf(
            formattedTime, sizeof(formattedTime), "%04d-%02d-%02d_%02d-%02d-%02d", logTime.year, logTime.month, logTime.day,
            logTime.hour, logTime.minute, logTime.second);

        std::string log_file = std::string(DEBUG_LOG_DIR) + formattedTime + ".log";

        g_log_fd = sceIoOpen(log_file.c_str(), SCE_O_WRONLY | SCE_O_CREAT | SCE_O_TRUNC, 0777);
    }

    return 0;
}

int _log_printf(int level, const char* format, ...)
{

    va_list args;
    va_start(args, format);

    char buf[512];
    vsnprintf(buf, 512, format, args);

    char buf_colored[600];
    switch (level)
    {
        case DBG_INFO:
            snprintf(buf_colored, 600, "\033[1;34;7m[INFO]\033[0m\033[1;34m %s\033[0m", buf);
            break;
        case DBG_ERROR:
            snprintf(buf_colored, 600, "\033[1;31;7m[ERROR]\033[0m\033[1;31m %s\033[0m", buf);
            break;
        case DBG_WARNING:
            snprintf(buf_colored, 600, "\033[1;35;7m[WARNING]\033[0m\033[1;35m %s\033[0m", buf);
            break;
        case DBG_DEBUG:
            snprintf(buf_colored, 600, "\033[1;30;7m[DEBUG]\033[0m\033[1;30m %s\033[0m", buf);
            break;
        case DBG_NONE:
        default:
            snprintf(buf_colored, 600, "\033[1;31;7m[UNK]\033[0m\033[1;31m %s\033[0m", buf);
            break;
    }

    va_end(args);

    #if (DEBUG_APP == 1 && DEBUG_NET == 1)
        debugNetUDPSend(buf_colored);
    #endif

    #if (DEBUG_APP == 1 && DEBUG_LOG == 1)
        sceIoWrite(g_log_fd, buf, strlen(buf));
        sceIoSyncByFd(g_log_fd);
    #endif

    return 0;
}

int log_term() {
    #if (DEBUG_APP == 1 && DEBUG_NET == 1)
        debugNetFinish();
    #endif
    return 0;
}