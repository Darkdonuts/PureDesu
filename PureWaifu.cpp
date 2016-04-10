#include "pured_utils.h"

#define TESTDB "TestDB"

static unsigned int flags = boost::archive::no_header;
BOOST_CLASS_IMPLEMENTATION(PureWaifu, object_serializable);

const string PureWaifu::ANIM_DB_FILE = "animdb.xml";

const unordered_map<string, string> PureWaifu::ICON {
    make_pair("happy",     "happy.png"),
    make_pair("annoyed",   "annoyed.png"),
    make_pair("confused",  "confused.png"),
    make_pair("surprised", "surprised.png")
};

const unordered_map<string, string> PureWaifu::MESSAGE {
    make_pair("welcome", "Welcome back, " + MASTER_NAME + "!"),
    make_pair("error",   "ERROR!"),
    make_pair("oh",      "Ooooh"),
    make_pair("scared",  "That scared me, " + MASTER_NAME + "...")
};


PureWaifu::PureWaifu()
{
    DOWHAT_WITH_FILE = NOT_SET;

    terminal = true;
    notification = false;

    icon = ICON.at("happy");
    message = "";
}

#ifdef TESTAREA
void PureWaifu::TEST_SAVE_ANIMDB()
{
    anim_db["junk"].name = "junk name";
    anim_db["junk"].genres.insert("junkgenre1");
    anim_db["junk"].genres.insert("junkgenre2");
    anim_db["junk"].genres.insert("junkgenre3");
    anim_db["junk"].rating = 3.5;

    anim_db["garbage"].name = "garbage name";
    anim_db["garbage"].genres.insert("garbagegenre1");
    anim_db["garbage"].genres.insert("garbagegenre2");
    anim_db["garbage"].genres.insert("garbagegenre3");
    anim_db["garbage"].rating = 8.2;
    anim_db["garbage"].favorite = true;

    DOWHAT_WITH_FILE = SAVE_ANIM_DB;
    std::ofstream ofile(ANIM_DB_FILE);
    boost::archive::xml_oarchive oa(ofile, flags);
    oa << make_nvp(TESTDB, *this);

    DOWHAT_WITH_FILE = NOT_SET;
    cerr << "Saved: " TESTDB " in " << ANIM_DB_FILE << endl;

}
#endif

void PureWaifu::sendNotification()
{
    cerr << __FILE__ << ':' << __LINE__ << ':'
         << " WARNING: Notifications not implemented yet" << endl;
}

void PureWaifu::setMood(const string &m)
{
#ifndef NDEBUG
    cerr << __FILE__ << ':' << __LINE__ << ": ["
         << m << "] mood requested" << endl;
#endif

    if (ICON.find(m) != ICON.end())
        icon = ICON.at(m);
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
    if (MESSAGE.find(m) != MESSAGE.end()) {
        message = MESSAGE.at(m);
        sendNotification();
        cout << WAIFU_NAME << ": " << message << endl;
#ifndef NDEBUG
        cerr << __FILE__ << ':' << __LINE__ << ": [" << message
             << "] message set" << endl;
#endif
    } else {
        cerr << "ERROR: [" << m << "] message is unknown" << endl;
    }

}

void PureWaifu::version()
{
    cout << "Version: " << PURE_VERSION << endl;
}
