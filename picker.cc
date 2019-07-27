#include "support.h"

int main() {
  bool releasable = ask_question(
      "Would you like to include releasable countries? (y/n) ");
  std::vector<std::string> countryVec;
  if (releasable) populate_list(countryVec, "releasable");
  populate_list(countryVec, "countrylist");
  std::random_device rannum;
  std::mt19937 rng(rannum());
  std::uniform_int_distribution<std::mt19937::result_type> 
      dist(0, countryVec.size()-1);
  std::cout << "Country: " << remove_underscore(countryVec[dist(rng)]) 
      << std::endl;
  std::cin.ignore(1);  // clear cin stream and keep the window open for input
  std::cin.get();
  return 0;
}