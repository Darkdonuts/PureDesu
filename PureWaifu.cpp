#include "pured_utils.h"

void PureWaifu::sendNotification()
{
    std::cerr << __FILE__ << ':' << __LINE__ << ':'
              << " WARNING: Notifications not implemented yet" << std::endl;
}

PureWaifu::PureWaifu()
{
    terminal = true;
    notification = true;
    icon = _icons[0];
    message = "";

#define FICON
#ifndef FICON
    std::cerr << __FILE__ <<':'<< __LINE__ << ": ["
              << icon << "] icon set" << std::endl;
#endif
}

const string PureWaifu::_icons[] = {
    "happy.png",
    "annoyed.png",
    "confused.png",
    "surprised.png",
};

const string PureWaifu::_messages[] = {
    "Welcome back, " + master_name + "!",
    "ERROR!",
    "Ooooh",
    "That scared me, " + master_name + "..."
};

void PureWaifu::setMood(const string &m)
{
    std::cerr << __FILE__ << ':' << __LINE__ << ": ["
              << m << "] mood requested" << std::endl;
 
    if (m == "happy")
        icon = _icons[0];
    else if (m == "annoyed")
        icon = _icons[1];
    else if (m == "confused")
        icon = _icons[2];
    else if (m == "surprised")
        icon = _icons[3];
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
    else if (m == "notification")
        notification = true;
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

    if (m == "welcome")
        message = _messages[0];
    else if (m == "error")
        message = _messages[1];
    else if (m == "oh")
        message = _messages[2];
    else if (m == "scared")
        message = _messages[3];
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
