#include "nation.h"

std::vector<nation> nation::generate_list(const std::string& fileName) {
  std::vector<nation> nationList;
  std::ifstream ist{ fileName };
  nation name;
  while (ist >> name.country >> name.releaser >> name.nonideology) {
    nationList.push_back(name);
  }
  return nationList;
}

nation nation::choose_random(std::vector<nation>& nationVec, bool releasable) {
  srand(time(NULL));
  nation country = nationVec[rand() % nationVec.size()];
  while (!releasable && country.releaser != "N")
    country = nationVec[rand() % nationVec.size()];
  return country;
}

void nation::print_country(const std::string& ideology) {
  std::cout << "Your country is: " << country << " ";
  if (releaser != "N")
    std::cout << "(" << releaser << ")" << std::endl;
  else
    std::cout << std::endl;
  std::cout << "Your ideology is: " << ideology << std::endl;
}

std::string nation::choose_ideology(std::vector<std::string>& ideologylist) {
  srand(time(NULL));
  std::string ideology{ ideologylist[rand() % ideologylist.size()] };
  while (!nonideology && ideology == "Non-Aligned")
    ideology = ideologylist[rand() % ideologylist.size()];
  return ideology;
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

void nation::remove_underscore() {
  for (int i = 0; i < country.size(); ++i)
    if (country[i] == '_') country[i] = ' ';
  for (int i = 0; i < releaser.size(); ++i)
    if (releaser[i] == '_') releaser[i] = ' ';
  return;
}

void populate_list(
  std::vector<std::string>& vec, const std::string& fileName){
  std::ifstream ist{ fileName };
  std::string current;
  while (ist >> current) vec.push_back(current);
}

