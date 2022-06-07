#include "person.h"

namespace exchangeTJ
{

Person::Person(std::string name, std::string email, std::string current_city,
  std::string first_desire_city) :
    m_name(std::move(name)),
    m_email(std::move(email)), m_current_city(std::move(current_city)),
    m_first_desire_city(std::move(first_desire_city))
{
}

Person::Person(std::string name, std::string email, std::string current_city,
  std::string first_desire_city, std::string second_option_city) :
    m_name(std::move(name)),
    m_email(std::move(email)), m_current_city(std::move(current_city)),
    m_first_desire_city(std::move(first_desire_city)),
    m_second_option_city(std::move(second_option_city))
{
}

Person::Person(std::string name, std::string email, std::string current_city,
  std::string first_desire_city, std::string second_option_city,
  std::string third_option_city) :
    m_name(std::move(name)),
    m_email(std::move(email)), m_current_city(std::move(current_city)),
    m_first_desire_city(std::move(first_desire_city)),
    m_second_option_city(std::move(second_option_city)),
    m_third_option_city(std::move(third_option_city))
{
}

bool Person::is_valid() const
{
  return !m_name.empty() && !m_email.empty() && !m_current_city.empty() &&
    !m_first_desire_city.empty() && (m_current_city != m_first_desire_city);
}

std::string Person::name() const
{
  return m_name;
}

std::string Person::email() const
{
  return m_email;
}

std::string Person::current_city() const
{
  return m_current_city;
}

std::vector<std::string> Person::desire_cities() const
{
  std::vector<std::string> desired_cities;

  desired_cities.push_back(m_first_desire_city);

  if (m_second_option_city.has_value())
  {
    desired_cities.push_back(m_second_option_city.value());
  }

  if (m_third_option_city.has_value())
  {
    desired_cities.push_back(m_third_option_city.value());
  }
  return desired_cities;
}

bool Person::operator==(const Person& rhs) const
{
  return this->m_email == rhs.m_email;
}

std::ostream& operator<<(std::ostream& os, const Person& person)
{
  os << person.name() << ' ' << person.email() << ' ' << person.current_city()
     << ' ' << person.m_first_desire_city << ' '
     << person.m_second_option_city.value_or("") << ' '
     << person.m_third_option_city.value_or("") << '\n';

  return os;
}

} // namespace exchangeTJ