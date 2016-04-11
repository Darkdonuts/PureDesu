/////////////////////////////////////////////////////////////////////////////
// Here are declared all the variables, functions and objects needed for her
// to run properly. <-- bad idea, needs a pure_imouto.h
/////////////////////////////////////////////////////////////////////////////
#ifndef _PURE_UTILS_
#define _PURE_UTILS_

#define NDEBUG
#define TESTAREA

#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/set.hpp>
#include <boost/serialization/nvp.hpp>

#include <iostream>
#include <fstream>

#include <unordered_map>
#include <vector>
#include <map>
#include <set>

using std::cout;
using std::cerr;
using std::endl;
using std::make_pair;
using std::string;
using std::unordered_map;
using std::map;
using std::set;
using std::vector;

using boost::serialization::make_nvp;

static const string ICON_PATH       = "~/dev/PureDesu/icons/";
static const string WAIFU_NAME      = "PureDesu@Awaii";
static const string MASTER_NAME     = "Onigiri-kun";
static const string NOTIFICATION_T  = "7000";
static const string PURE_VERSION    = "0.01a";

struct Anime {
    string name;
    set<string> genres;
    float rating  = 0.0;
    bool favorite = false;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & make_nvp("Anime_Name",     name);
        ar & make_nvp("Anime_Genres",   genres);
        ar & make_nvp("Anime_Rating",   rating);
        ar & make_nvp("Anime_Favorite", favorite);

    }
};

class PureWaifu {
    friend boost::serialization::access;
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        switch (DOWHAT_WITH_FILE) {
            case SAVE_ANIM_DB:
            case LOAD_ANIM_DB:
                ar & make_nvp("AnimeDatabase", anim_db);
                break;
            case NOT_SET:
                cerr << "ERROR: DOWHAT_WITH_FILE NOT SET" << endl;
                break;
        }
    }

    enum FILE_OPERATIONS {

        SAVE_ANIM_DB,
        LOAD_ANIM_DB,
        NOT_SET

    } DOWHAT_WITH_FILE;

    private:
        static const unordered_map<string, string> ICON;
        static const unordered_map<string, string> MESSAGE;
        static const string ANIM_DB_FILE;

        string icon;
        string message;
        map<string, Anime> anim_db;

        bool terminal;
        bool notification;
        void sendNotification();

    public:
        PureWaifu();
        void setMood(const string &mood);
        void setMode(const string &mode);
        void say(const string &msg);
        void version();

        /////////TESTAREA//////////////
#ifdef TESTAREA
        void TEST_SAVE_ANIMDB();
#endif
};

#endif
