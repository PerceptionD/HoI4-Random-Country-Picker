#include "support.h"
#include <stdexcept>

int main()
try {
    std::vector<nation> countryVec;
    std::vector<std::string> ideologyVec;
    std::vector<std::string> nonalignable;
    std::string ideology;

    populate_list(ideologyVec, "ideology");
    populate_list(nonalignable, "nonalignable");

    bool again = true;
    while (again) {
    bool releasable = ask_question(
      "Would you like to include releasable countries? (y/n) ");

  if (releasable) 
    nation::populate_pair_list(countryVec, "releasable");
  nation::populate_country_list(countryVec, "countrylist");


  srand(time(NULL));
  
    nation country = countryVec[rand() % countryVec.size()];
    std::cout << "Country: " << nation::remove_underscore(country);
    if (country.releaser != "")
        std::cout << " (" << nation::remove_releaser_underscore(country) 
        << ")" << std::endl;
    else std::cout << std::endl;

    if (std::count(nonalignable.begin(), nonalignable.end(), country.country) == 0)
      ideologyVec.erase(std::remove(ideologyVec.begin(), ideologyVec.end(),
          "Non-Aligned"), ideologyVec.end());
    ideology = ideologyVec[rand() % ideologyVec.size()];

    std::cout << "Ideology: " << ideology << std::endl;
    again = ask_question("Would you like to generate another? (y/n)");
    countryVec.clear();
  }
  return 0;
}

catch (std::exception& e) {
    std::cerr << "error: " << e.what() << '\n';
    std::cin.get();
    return 1;
}

catch (...) {
    std::cerr << "Oops: unknown exception!\n";
    std::cin.get();
    return 2;
}