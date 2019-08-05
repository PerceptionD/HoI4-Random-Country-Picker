#ifndef HOICOUNTRYPICKER_SUPPORT_H_
#define HOICOUNTRYPICKER_SUPPORT_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include <time.h>
class nation
{
  std::string releaser;
  std::string country;
  bool nonideology;

public:
  // populates a vector of nations from a file
  static std::vector<nation> generate_list(const std::string&);
  // removes the underscores from the strings and replaces them with spaces
  void remove_underscore();
  // chooses a random nation from a vector of nations
  // respects choice to include releasable nations
  nation choose_random(std::vector<nation>&, bool);
  // chooses an ideology from a vector of ideologies
  std::string choose_ideology(std::vector<std::string>&);
  // prints the country, releaser (if applicable) and ideology of the nation
  void print_country(const std::string&);
 
  nation() {
    country = "";
    releaser = "";
    nonideology = false;
  }
};

// Accepts a string input as a question to ask the user. 
// The user is prompted to respond with a y/Y or a n/N.
bool ask_question(std::string);
// Populates a vector of strings using a file input.
void populate_list(std::vector<std::string>&, const std::string&);

#endif	// HOICOUNRYPICKER_SUPPORT_H_