#include "pured_utils.h"
#define NDEBUG

void PureWaifu::sendNotification()
{
    cerr << __FILE__ << ':' << __LINE__ << ':'
              << " WARNING: Notifications not implemented yet" << endl;
}

PureWaifu::PureWaifu()
{
    terminal = true;
    notification = false;
    icon = _ICON.at("happy");
    message = "";

#define FICON
#ifndef FICON
    cerr << __FILE__ <<':'<< __LINE__ << ": ["
              << icon << "] icon set" << endl;
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
    cerr << __FILE__ << ':' << __LINE__ << ": ["
              << m << "] mood requested" << endl;
#endif

    if (_ICON.find(m) != _ICON.end())
        icon = _ICON.at(m);
    else
        cerr << "ERROR: [" << m << "] mood is unknown" << endl;

#ifndef NDEBUG
    cerr << __FILE__ << ':' << __LINE__ << ": [" << icon
              << "] icon set" << endl;
#endif
}

void PureWaifu::setMode(const string &m)
{
#ifndef NDEBUG
    cerr << __FILE__ << ':' << __LINE__ << ": [" << m
              << "] mode requested" << endl;
#endif

    if (m == "terminal")
        notification = false;
    else if (m == "notification" && !notification)
        notification = true;
    else if (m == "notification" && notification)
        cerr << "[notification] mode is already set" << endl;
    else
        cerr << "ERROR: [" << m << "] mode is unknown" << endl;

#ifndef NDEBUG
    cerr << __FILE__ << ':' << __LINE__ << ':'
              << (terminal && notification ? " [notification]" : " [terminal]")
              << " mode set" << endl;
#endif
}

void PureWaifu::say(const string &m)
{
#ifndef NDEBUG
    cerr << __FILE__ << ':' << __LINE__ << ": ["
              << m << "] message requested" << endl;
#endif

    if (_MESSAGE.find(m) != _MESSAGE.end())
        message = _MESSAGE.at(m);
    else
        cerr << "ERROR: [" << m << "] message is unknown" << endl;

#ifndef NDEBUG
    cerr << __FILE__ << ':' << __LINE__ << ": [" << message
              << "] message set" << endl;
#endif

    if (notification)
        sendNotification();
    cout << waifu_name << ": " << message << endl;

}

void PureWaifu::version()
{
    cout << "Version: " << pure_version << endl;
}
