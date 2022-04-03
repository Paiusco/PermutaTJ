#include <catch2/catch.hpp>

#include "../src/person.h"

TEST_CASE("Valid person", "[person]")
{
  exchangeTJ::Person person{"João", "joao.silva@gmail.com", "São Paulo", "Campinas"};

  REQUIRE(person.is_valid() == true);
}

TEST_CASE("Invalid person", "[person]")
{
  exchangeTJ::Person persoan{"", "", "", ""};

  REQUIRE(persoan.is_valid() == false);
}

