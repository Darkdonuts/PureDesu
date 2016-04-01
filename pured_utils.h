/*
 * Here are declared all the variables, functions and objects needed for her
 * to run properly.
 */
#ifndef _PURE_UTILS_
#define _PURE_UTILS_

#include <iostream>

using std::string;

static const string icon_path       = "~/dev/PureDesu/icons/";
static const string waifu_name      = "PureDesu@Awaii";
static const string master_name     = "Onigiri-kun";
static const string _time           = "7000";     // for the notification time out
static const string pure_version    = "0.01a";

class PureWaifu {
    private:
        static const string _icons[];
        static const string _messages[];

        string icon;
        string message;

        bool terminal;
        bool notification;
        void sendNotification();
    public:
        PureWaifu();

        /* mood:
         * { "happy",    "annoyed",
         *   "confused", "surprised" } */
        void setMood(const string &mood);

        /* mode:
         * { "terminal"       // talks through the terminal only
         *   "notification" } // talks using both terminal and notifications */
        void setMode(const string &mode);

        /* msg:
         * { "welcome", "error"
         *   "oh", "scared" } */
        void say(const string &msg);

        void version();
};

#endif
