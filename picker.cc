#include "nation.h"
#include <stdexcept>

int main()
try {
  // populate the list of possible countries from file
  std::vector<nation> nationVec = nation::generate_list("countrylist");
  std::vector<std::string> ideologyVec;
  std::string ideology;
  nation country;

  populate_list(ideologyVec, "ideology");

  bool again{ true };
  while (again) {
    bool releasable = ask_question(
      "Would you like to include releasable countries? (y/n) ");

    country = country.choose_random(nationVec, releasable);
    country.remove_underscore();
    ideology = country.choose_ideology(ideologyVec);
    country.print_country(ideology);

    again = ask_question("Would you like to generate another? (y/n)");
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