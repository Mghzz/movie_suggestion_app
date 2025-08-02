#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <utility>
#include <memory>
#include <unordered_map>
#include <algorithm>
using namespace std;

#ifndef INCLUDE_HPP
#define INCLUDE_HPP

const string SCIENCE_FICTION = "Science Fiction";
const string ACTION = "Action";
const string COMEDY = "Comedy";
const string DRAMA = "Drama";
const string HORROR = "Horror";
const string GENRE_REC = "genre_recommandation";
const string CAST_REC = "cast_recommandation";
const string PERFECT = "Perfect";
const string AVERAGE = "Average";
const string POOR = "Poor";
const char COMMA = ',';
const char SEMICOLON = ';';
const char SPACE = ' ';

extern unordered_map<string, int> genres;

inline vector<string> split_string(const string &str, char delimiter)
{
    vector<string> tokens;
    string token;
    istringstream sstr(str);
    while (getline(sstr, token, delimiter))
    {
        tokens.push_back(move(token));
    }
    return tokens;
}

#endif