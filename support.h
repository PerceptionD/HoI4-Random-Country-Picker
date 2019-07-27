#ifndef HOICOUNTRYPICKER_SUPPORT_H_
#define HOICOUNTRYPICKER_SUPPORT_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <random>
// Populates a vector of strings using a file input.
void populate_list(std::vector<std::string>&, std::string);
// Accepts a string input as a question to ask the user. The user is prompted to respond
// with a y/Y or a n/N.
bool ask_question(std::string);
// Accepts a string and replaces all instances of '_' with ' '.
std::string remove_underscore(std::string);

#endif	// HOICOUNRYPICKER_SUPPORT_H_