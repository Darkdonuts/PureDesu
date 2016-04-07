#include "pured_utils.h"
#define NDEBUG

void PureWaifu::sendNotification()
{
    std::cerr << __FILE__ << ':' << __LINE__ << ':'
              << " WARNING: Notifications not implemented yet" << std::endl;
}

PureWaifu::PureWaifu()
{
    terminal = true;
    notification = false;
    icon = _ICON.at("happy");
    message = "";

#define FICON
#ifndef FICON
    std::cerr << __FILE__ <<':'<< __LINE__ << ": ["
              << icon << "] icon set" << std::endl;
#endif
}

const unordered_map<string, string> PureWaifu::_ICON {
    make_pair("happy",     "happy.png"),
    make_pair("annoyed",   "annoyed.png"),
    make_pair("confused",  "confused.png"),
    make_pair("surprised", "surprised.png")
};

const unordered_map<string, string> PureWaifu::_MESSAGE {
    make_pair("welcome", "Welcome back, " + master_name + "!"),
    make_pair("error",   "ERROR!"),
    make_pair("oh",      "Ooooh"),
    make_pair("scared",  "That scared me, " + master_name + "...")
};

void PureWaifu::setMood(const string &m)
{
#ifndef NDEBUG
    std::cerr << __FILE__ << ':' << __LINE__ << ": ["
              << m << "] mood requested" << std::endl;
#endif
 
    if (_ICON.find(m) != _ICON.end())
        icon = _ICON.at(m);
    else
        std::cerr << "ERROR: [" << m << "] mood is unknown" << std::endl;

#ifndef NDEBUG
    std::cerr << __FILE__ << ':' << __LINE__ << ": [" << icon
              << "] icon set" << std::endl;
#endif
}

void PureWaifu::setMode(const string &m)
{
#ifndef NDEBUG
    std::cerr << __FILE__ << ':' << __LINE__ << ": [" << m
              << "] mode requested" << std::endl;
#endif

    if (m == "terminal")
        notification = false;
    else if (m == "notification" && !notification)
        notification = true;
    else if (m == "notification" && notification)
        std::cerr << "[notification] mode is already set" << std::endl;
    else
        std::cerr << "ERROR: [" << m << "] mode is unknown" << std::endl;

#ifndef NDEBUG
    std::cerr << __FILE__ << ':' << __LINE__ << ':'
              << (terminal && notification ? " [notification]" : " [terminal]")
              << " mode set" << std::endl;
#endif
}

void PureWaifu::say(const string &m)
{
#ifndef NDEBUG
    std::cerr << __FILE__ << ':' << __LINE__ << ": ["
              << m << "] message requested" << std::endl;
#endif

    if (_MESSAGE.find(m) != _MESSAGE.end())
        message = _MESSAGE.at(m);
    else
        std::cerr << "ERROR: [" << m << "] message is unknown" << std::endl;

#ifndef NDEBUG
    std::cerr << __FILE__ << ':' << __LINE__ << ": [" << message
              << "] message set" << std::endl;
#endif

    if (notification)
        sendNotification();
    std::cout << waifu_name << ": " << message << std::endl;

}

void PureWaifu::version()
{
    std::cout << "Version: " << pure_version << std::endl;
}
