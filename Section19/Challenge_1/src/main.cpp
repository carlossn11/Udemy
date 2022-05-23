// Section 19
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
  std::string name;
  long population;
  double cost;
};

// Assume each country has at least 1 city
struct Country {
  std::string name;
  std::vector<City> cities;
};

struct Tours {
  std::string title;
  std::vector<Country> countries;
};

int getCenterAlignment(const std::string &title) {
  return ((39 - title.size())/2)-1;
}

std::string AddCommas(const std::string &population) {
  switch (population.size()) {
    case 6: {
      return population.substr(0, 3) + ',' + population.substr(3);
    }
    case 7: 
    case 8: {
      return population.substr(0, 2) + ',' + population.substr(2, 3) + ',' + population.substr(5);
    }
  }
  return "Not valid";
}

int main() {
  Tours tours { 
    "Tour Ticket Prices from Miami",
    {
      {
        "Colombia", { 
          { "Bogota", 8778000, 400.98 },
          { "Cali", 2401000, 424.12 },
          { "Medellin", 2464000, 350.98 },
          { "Cartagena", 972000, 345.34 } 
        },
      },
      {
        "Brazil", { 
          { "Rio De Janiero", 13500000, 567.45 },
          { "Sao Paulo", 11310000, 975.45 },
          { "Salvador", 18234000, 855.99 }
        },
      },
      {
        "Chile", { 
          { "Valdivia", 260000, 569.12 }, 
          { "Santiago", 7040000, 520.00 }
        },
      },
      { 
        "Argentina", { 
          { "Buenos Aires", 3010000, 723.77 } 
        } 
      },
    }
  };

  // Unformatted display so you can see how to access the vector elements
  std::cout << std::setw(getCenterAlignment(tours.title)) << ' ' << tours.title << std::endl;
  for(const auto &country : tours.countries) {   // loop through the countries
    std::cout << "Destination:" << std::setw(26) << country.name << std::endl;
    std::cout << std::setfill('-') << std::setw(39) << '\n' << std::setfill(' ');
    std::cout << std::left;
    std::cout << std::setw(15) << "City" << std::setw(19) << "Population" << std::setw(8) << "Cost" << '\n';
    std::cout << std::right;
    std::cout << std::setfill('-') << std::setw(39) << '\n' << std::setfill(' ');

    for(const auto &city : country.cities) {       // loop through the cities for each country
      std::cout << std::left << std::setw(15) << city.name;
      std::cout << std::setw(16) << AddCommas(std::to_string(city.population));
      std::cout << std::right << std::setprecision(2) << std::fixed << '$' << city.cost 
      << std::endl;
    }
    std::cout << "\n";
  }
  return 0;
}