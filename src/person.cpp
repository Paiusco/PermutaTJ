#include "person.h"

namespace exchangeTJ
{

Person::Person(const std::string& name, const std::string& email,
  const std::string& current_city, const std::string& main_desire_city)
    : m_name(std::move(name)), m_email(std::move(email)), 
      m_current_city(std::move(current_city)), 
      m_main_desire_city(std::move(main_desire_city))
{

}

Person::Person(const std::string& name, const std::string& email,
  const std::string& current_city, const std::string& main_desire_city,
  const std::string& second_option_city)
    : m_name(std::move(name)), m_email(std::move(email)), 
      m_current_city(std::move(current_city)), 
      m_main_desire_city(std::move(main_desire_city)),
      m_second_option_city(second_option_city)
{

}

Person::Person(const std::string& name, const std::string& email,
  const std::string& current_city, const std::string& main_desire_city,
  const std::string& second_option_city, const std::string& third_option_city)
    : m_name(std::move(name)), m_email(std::move(email)), 
      m_current_city(std::move(current_city)), 
      m_main_desire_city(std::move(main_desire_city)),
      m_second_option_city(second_option_city),
      m_third_option_city(third_option_city)
{

}

bool
Person::is_valid() const
{
  return !m_name.empty() && !m_email.empty() && !m_current_city.empty();
}
} // namespace exchangeTJ