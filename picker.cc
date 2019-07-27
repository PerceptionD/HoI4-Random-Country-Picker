#include "support.h"

int main() {
  bool releasable = ask_question(
      "Would you like to include releasable countries? (y/n) ");

  std::vector<std::string> countryVec;
  std::vector<std::string> ideologyVec;
  std::vector<std::string> nonalignable;
  std::string ideology;

  if (releasable) 
    populate_list(countryVec, "releasable");
  populate_list(countryVec, "countrylist");
  populate_list(ideologyVec, "ideology");
  populate_list(nonalignable, "nonalignable");

  srand(time(NULL));
  std::string country = countryVec[rand() % countryVec.size()];
  std::cout << "Country: " << remove_underscore(country) << std::endl;

  if (std::count(nonalignable.begin(), nonalignable.end(), country) == 0)
    ideologyVec.erase(std::remove(ideologyVec.begin(), ideologyVec.end(),
        "Non-Aligned"), ideologyVec.end());
  ideology = ideologyVec[rand() % ideologyVec.size()];

  std::cout << "Ideology: " << ideology << std::endl;
  std::cin.ignore(1);  // clear cin stream and keep the window open for input
  std::cin.get();
  return 0;
}