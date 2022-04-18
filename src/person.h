#ifndef SRC_PERSON_H_
#define SRC_PERSON_H_

#include <optional>
#include <ostream>
#include <string>
#include <vector>
namespace exchangeTJ
{

class Person
{
public:
  Person(std::string name, std::string email, std::string current_city,
    std::string first_desire_city);

  Person(std::string name, std::string email, std::string current_city,
    std::string first_desire_city, std::string second_option_city);

  Person(std::string name, std::string email, std::string current_city,
    std::string first_desire_city, std::string second_option_city,
    std::string third_option_city);

  std::string name() const;
  std::string email() const;
  std::string current_city() const;
  std::vector<std::string> desire_cities() const;

  bool is_valid() const;

  bool operator==(const Person& rhs) const;
  friend std::ostream& operator<<(std::ostream& os, const Person& person);

private:
  std::string m_name;
  std::string m_email;
  std::string m_current_city;
  std::string m_first_desire_city;
  std::optional<std::string> m_second_option_city;
  std::optional<std::string> m_third_option_city;
};

} // namespace exchangeTJ

#endif /* SRC_PERSON_H_ */
