/*
 * GenreObject: This object manages a set of genres
 */
#ifndef _GENREOBJECT_
#define _GENREOBJECT_

#include <iostream>
#include <set>

using std::string;
using std::set;

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
