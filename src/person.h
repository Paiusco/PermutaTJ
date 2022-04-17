#ifndef SRC_PERSON_H_
#define SRC_PERSON_H_

#include <optional>
#include <string>

namespace exchangeTJ
{

class Person
{
public:
  Person(const std::string& name, const std::string& email,
    const std::string& current_city, const std::string& main_desire_city);

  Person(const std::string& name, const std::string& email,
    const std::string& current_city, const std::string& main_desire_city,
    const std::string& second_option_city);

  Person(const std::string& name, const std::string& email,
    const std::string& current_city, const std::string& main_desire_city,
    const std::string& second_option_city,
    const std::string& third_option_city);

  bool is_valid() const;

private:
  std::string m_name;
  std::string m_email;
  std::string m_current_city;
  std::string m_main_desire_city;
  std::optional<std::string> m_second_option_city;
  std::optional<std::string> m_third_option_city;
};

} // namespace exchangeTJ

#endif /* SRC_PERSON_H_ */
