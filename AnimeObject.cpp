#include "pured_utils.h"

AnimeObject::AnimeObject()
{
    rating = 0.0;
    favorite = false;
}

void AnimeObject::setName(const string &n)
{
    name = n;
}

void AnimeObject::addGenre(const string &g)
{
    genres.insert(g);
}

void AnimeObject::setRating(const float r)
{
    rating = r;
}

void AnimeObject::setFavorite()
{
    favorite = true;
}

const string& AnimeObject::getName() const
{
    return name;
}

const set<string>& AnimeObject::getGenres() const
{
    return genres;
}

float AnimeObject::getRating() const
{
    return rating;
}

bool AnimeObject::isFavorite() const
{
    return favorite;
}

void AnimeObject::removeGenre(const string &g)
{
    genres.erase(g);
}
