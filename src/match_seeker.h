#ifndef SRC_MATCH_SEEKER_H
#define SRC_MATCH_SEEKER_H

#include "person.h"

#include <memory>
#include <vector>

namespace exchangeTJ
{

class MatchSeeker
{
public:
  explicit MatchSeeker(std::shared_ptr<std::vector<Person>> data);

  std::vector<std::pair<Person, Person>> find_depth_one() const;

private:
  static bool is_match(const Person& p1, const Person& p2);

  std::shared_ptr<std::vector<Person>> m_data;
};

} // namespace exchangeTJ

#endif // SRC_MATCH_SEEKER_H