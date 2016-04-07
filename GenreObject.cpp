#include "pured_utils.h"

const set<string>& GenreObject::get() const
{
    return genres;
}

bool GenreObject::find(const string &g) const
{
    if (genres.find(g) != genres.end())
        return true;
    return false;
}

void GenreObject::add(const string &g)
{
    genres.insert(g);
}

void GenreObject::remove(const string &g)
{
    genres.erase(g);
}
