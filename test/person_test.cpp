#include "../src/person.h"

#include <catch2/catch.hpp>

TEST_CASE("Valid person", "[person]")
{
  exchangeTJ::Person valid_person{
    "João", "joao.silva@gmail.com", "São Paulo", "Campinas"};

  REQUIRE(valid_person.is_valid() == true);
}

TEST_CASE("Invalid person w/o fields", "[person]")
{
  exchangeTJ::Person empty_person{"", "", "", ""};

  REQUIRE(empty_person.is_valid() == false);
}

TEST_CASE("Invalid person wants to go to same city", "[person")
{
  exchangeTJ::Person cities_shouldnt_match_person{
    "João", "joao.silva@gmail.com", "Campinas", "Campinas"};

  REQUIRE(cities_shouldnt_match_person.is_valid() == false);
}

TEST_CASE("Correct amount of desired cities", "[person]")
{
  SECTION("Only one desired city")
  {
    exchangeTJ::Person only_one_desired{
      "Jorge", "jorge@pm.me", "Campinas", "Ubatuba"};
    REQUIRE(only_one_desired.desire_cities().size() == 1);
  }

  SECTION("Two desired city")
  {
    exchangeTJ::Person two_desired{
      "Jorge", "jorge@pm.me", "Campinas", "Ubatuba", "Bauru"};
    REQUIRE(two_desired.desire_cities().size() == 2);
  }

  SECTION("Three desired city")
  {
    exchangeTJ::Person three_desired{
      "Jorge", "jorge@pm.me", "Campinas", "Ubatuba", "Bauru", "Ibaté"};
    REQUIRE(three_desired.desire_cities().size() == 3);
  }
}