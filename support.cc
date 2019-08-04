#include "support.h"

void populate_list(
    std::vector<std::string>& countryList, const std::string& fileName) {
    std::ifstream ist{ fileName };
    std::string name;
    while (ist >> name)
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

std::string nation::remove_underscore(nation& country) {
  for (int i = 0; i < country.country.size(); ++i)
    if (country.country[i] == '_') country.country[i] = ' ';
  return country.country;
}
std::string nation::remove_releaser_underscore(nation& country) {
    for (int i = 0; i < country.releaser.size(); ++i)
        if (country.releaser[i] == '_') country.releaser[i] = ' ';
    return country.releaser;
}

void nation::populate_pair_list(
    std::vector<nation>& countryVec, const std::string& fileName){
    std::ifstream ist{ fileName };
    nation country;
    while (ist >> country.country >> country.releaser)
        countryVec.emplace_back(country);

}

void nation::populate_country_list(
    std::vector<nation>& countryList, const std::string& fileName) {
    std::ifstream ist{ fileName };
    nation name;
    while (ist >> name.country)
        countryList.emplace_back(name);
}
