/*
 * Here are declared all the variables, functions and objects needed for her
 * to run properly.
 */
#ifndef _PURE_UTILS_
#define _PURE_UTILS_

#include <iostream>
#include <unordered_map>
#include <set>

using std::string;
using std::unordered_map;
using std::make_pair;
using std::set;

static const string icon_path       = "~/dev/PureDesu/icons/";
static const string waifu_name      = "PureDesu@Awaii";
static const string master_name     = "Onigiri-kun";
static const string _time           = "7000";     // for the notification time out
static const string pure_version    = "0.01a";

class PureWaifu {
    private:
        static const unordered_map<string, string> _ICON;
        static const unordered_map<string, string> _MESSAGE;

        string icon;
        string message;

        bool terminal;
        bool notification;
        void sendNotification();
    public:
        PureWaifu();
        void setMood(const string &mood);
        void setMode(const string &mode);
        void say(const string &msg);
        void version();
};

class GenreObject {
    private:
        set<string> genres;
    public:
        const set<string>& get() const;
        bool find(const string &genre) const;
        void add(const string &genre);
        void remove(const string &genre);
};

#endif
