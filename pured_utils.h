/*
 * Here are declared all the variables, functions and objects needed for her
 * to run properly.
 */
#ifndef _PURE_UTILS_
#define _PURE_UTILS_

#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::unordered_map;
using std::make_pair;
using std::set;
using std::vector;

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

class AnimeObject {
    private:
        string name;
        set<string> genres;
        float rating;
        bool favorite;
        //GenreObject genre;
        //AnimeDateObject date; // contains date.ends and date.begins
    public:
        AnimeObject();
        void setName(const string &name);
        void addGenre(const string &genre);
        void setRating(const float rating);
        void setFavorite();

        const string& getName() const;
        const set<string>& getGenres() const;
        float getRating() const;
        bool isFavorite() const;

        void removeGenre(const string &genre);

};

#endif
