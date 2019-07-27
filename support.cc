#include "support.h"

void populate_list(
    std::vector<std::string>& countryList, std::string fileName) {
  std::ifstream ist { fileName };
  std::string name;
  while (ist>>name)
    countryList.push_back(name);
}

bool ask_question(std::string question) {
  std::string ch;
  std::cout << question << std::endl;
  while (std::cin >> ch) {
    if (ch=="y"||ch=="n"||ch=="Y"||ch=="N") break;
    std::cout << "Please answer with y or n." << std::endl;
  }
  if (ch=="y"||ch=="Y") return true;
  return false;
}

std::string remove_underscore(std::string phrase) {
  for (int i = 0; i < phrase.size(); ++i)
    if (phrase[i] == '_') phrase[i] = ' ';
  return phrase;
}
