#ifndef HOICOUNTRYPICKER_SUPPORT_H_
#define HOICOUNTRYPICKER_SUPPORT_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include <time.h>
struct nation
{
    
    std::string releaser;
    std::string country;
    static void populate_pair_list(std::vector<nation>& countryVec, const std::string&);
    static void populate_country_list(std::vector<nation>&, const std::string&);
    static std::string remove_underscore(nation& country);
    static std::string remove_releaser_underscore(nation& country);
    nation() {
        country = "";
        releaser = "";
    }
};

// Populates a vector of strings using a file input.

// Accepts a string input as a question to ask the user. 
// The user is prompted to respond with a y/Y or a n/N.
bool ask_question(std::string);
// Accepts a string and replaces all instances of '_' with ' '.


void populate_list(std::vector<std::string>&, const std::string&);

#endif	// HOICOUNRYPICKER_SUPPORT_H_