#include "match_seeker.h"

#include "person.h"

#include <algorithm>
#include <iostream>
#include <utility>

namespace exchangeTJ
{

MatchSeeker::MatchSeeker(std::shared_ptr<std::vector<Person>> data) :
    m_data(std::move(data))
{
}

std::vector<std::pair<Person, Person>> MatchSeeker::find_depth_one() const
{
  std::vector<std::pair<Person, Person>> matches;

  const auto& data = *m_data;
  for (auto it = data.begin(); it != data.end(); ++it)
  {
    for (auto it2 = it + 1; it2 != data.end(); ++it2)
    {
      if (is_match(*it, *it2))
      {
        std::cout << "Match found!\n";
        std::cout << "Between " << it->name() << " and " << it2->name() << '\n';
        matches.emplace_back(std::make_pair(*it, *it2));
      }
    }
  }

  return matches;
}

bool MatchSeeker::is_match(const Person& p1, const Person& p2)
{
  auto p1_desired_cities = p1.desire_cities();

  auto it_p1 = std::find(
    p1_desired_cities.begin(), p1_desired_cities.end(), p2.current_city());
  if (it_p1 == p1_desired_cities.end())
  {
    return false;
  }

  auto p2_desired_cities = p2.desire_cities();
  auto it_p2 = std::find(
    p2_desired_cities.begin(), p2_desired_cities.end(), p1.current_city());
  if (it_p2 == p2_desired_cities.end())
  {
    return false;
  }

  return true;
}
} // namespace exchangeTJ