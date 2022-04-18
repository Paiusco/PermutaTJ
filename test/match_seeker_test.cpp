#include "../src/match_seeker.h"
#include "../src/person.h"

#include <catch2/catch.hpp>
#include <iostream>
#include <memory>
#include <vector>

TEST_CASE("Depth one, one desired city", "[match]")
{
  SECTION("One match")
  {
    std::vector<exchangeTJ::Person> valid_data{
      {"João", "joao@gmail.com", "São Paulo", "Campinas"},
      {"Jefferson", "jef@gmail.com", "Campinas", "Taubaté"},
      {"Carlos", "carlos@gmail.com", "Taubaté", "Campinas"},
      {"testando", "ble@gmail.com", "Santos", "Ubatuba"},
    };

    exchangeTJ::MatchSeeker match{
      std::make_shared<std::vector<exchangeTJ::Person>>(valid_data)};

    auto matches = match.find_depth_one();
    REQUIRE(matches.size() == 1);
  }

  SECTION("Two matches")
  {
    std::vector<exchangeTJ::Person> valid_dataa{
      {"João", "joao@gmail.com", "São Paulo", "Campinas"},
      {"Jefferson", "jef@gmail.com", "Campinas", "Taubaté"},
      {"Carlos", "carlos@gmail.com", "Taubaté", "Campinas"},
      {"testando", "ble@gmail.com", "Santos", "Ubatuba"},
      {"Guilherme", "guilherme@gmail.com", "Taubaté", "Campinas"},
    };

    exchangeTJ::MatchSeeker match{
      std::make_shared<std::vector<exchangeTJ::Person>>(valid_dataa)};

    auto matches = match.find_depth_one();
    REQUIRE(matches.size() == 2);
  }
}

TEST_CASE("Depth one, two desired city", "[match]")
{
  SECTION("One match")
  {
    std::vector<exchangeTJ::Person> valid_data{
      {"João", "joao@gmail.com", "São Paulo", "Campinas", "Sorocaba"},
      {"Jefferson", "jef@gmail.com", "Campinas", "Viradouro", "Taubaté"},
      {"Carlos", "carlos@gmail.com", "Taubaté", "Pontal", "Campinas"},
      {"testando", "ble@gmail.com", "Santos", "Socorro", "Ubatuba"},
    };

    exchangeTJ::MatchSeeker match{
      std::make_shared<std::vector<exchangeTJ::Person>>(valid_data)};

    auto matches = match.find_depth_one();
    REQUIRE(matches.size() == 1);
  }

  SECTION("Two matches")
  {
    std::vector<exchangeTJ::Person> valid_data{
      {"João", "joao@gmail.com", "São Paulo", "Campinas", "Sorocaba"},
      {"Jefferson", "jef@gmail.com", "Campinas", "Viradouro", "Taubaté"},
      {"Carlos", "carlos@gmail.com", "Taubaté", "Pontal", "Campinas"},
      {"testando", "ble@gmail.com", "Santos", "Socorro", "Ubatuba"},
      {"Guilherme", "guilherme@gmail.com", "Taubaté", "Campinas", "Tanabi"},
    };

    exchangeTJ::MatchSeeker match{
      std::make_shared<std::vector<exchangeTJ::Person>>(valid_data)};

    auto matches = match.find_depth_one();
    REQUIRE(matches.size() == 2);
  }
}

TEST_CASE("Depth one, three desired city", "[match]")
{
  SECTION("One match")
  {
    std::vector<exchangeTJ::Person> valid_data{
      {"João", "joao@gmail.com", "São Paulo", "Campinas", "Sorocaba",
        "Botucatu"},
      {"Jefferson", "jef@gmail.com", "Campinas", "Viradouro", "Taubaté",
        "Botucatu"},
      {"Carlos", "carlos@gmail.com", "Taubaté", "Pontal", "Campinas",
        "Botucatu"},
      {"testando", "ble@gmail.com", "Santos", "Socorro", "Ubatuba", "Botucatu"},
    };

    exchangeTJ::MatchSeeker match{
      std::make_shared<std::vector<exchangeTJ::Person>>(valid_data)};

    auto matches = match.find_depth_one();
    REQUIRE(matches.size() == 1);
  }

  SECTION("Two matches")
  {
    std::vector<exchangeTJ::Person> valid_data{
      {"João", "joao@gmail.com", "São Paulo", "Campinas", "Sorocaba",
        "Botucatu"},
      {"Jefferson", "jef@gmail.com", "Campinas", "Viradouro", "Taubaté",
        "Botucatu"},
      {"Carlos", "carlos@gmail.com", "Taubaté", "Pontal", "Campinas",
        "Botucatu"},
      {"testando", "ble@gmail.com", "Santos", "Socorro", "Ubatuba", "Botucatu"},
      {"Guilherme", "guilherme@gmail.com", "Taubaté", "Campinas", "Tanabi",
        "Botucatu"},
    };

    exchangeTJ::MatchSeeker match{
      std::make_shared<std::vector<exchangeTJ::Person>>(valid_data)};

    auto matches = match.find_depth_one();
    REQUIRE(matches.size() == 2);
  }
}