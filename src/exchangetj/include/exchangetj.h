/**
 *******************************************************************************
 *
 *    File: exchangetj.h
 *
 *    Project: exchangeTJ
 *
 *    Author: André B. Paiusco
 *******************************************************************************
 */

#ifndef SRC_EXCHANGETJ_H_
#define SRC_EXCHANGETJ_H_

#include <memory>
#include <chrono>
#include <vector>

namespace exchangetj
{


class ExchangeTJ
{
public:
   using Ptr = std::shared_ptr<ExchangeTJ>;

   ExchangeTJ();
   virtual ~ExchangeTJ();

   bool init();
   void run();
   void add_person();
   void delete_person();

private:
   struct Person
   {
      std::time_t date;
      std::string m_name;
      std::string m_from_city;
      std::string m_to_city;
   };

   std::vector<Person> m_people;
};


} // namespace

#endif /* SRC_EXCHANGETJ_H_ */