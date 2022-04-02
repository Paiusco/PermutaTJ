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
#include <string>

namespace exchangetj
{


class ExchangeTJ
{
public:
   using Ptr = std::shared_ptr<ExchangeTJ>;

   ExchangeTJ();

   bool init();
   void run();
   void add_person();
   void delete_person();


   //minimum work for cereal
   int tempData{12};
   template <typename Archive>
   void save( Archive& ar ) const
   {
      ar( tempData );
   }
   template <typename Archive>
   void load( Archive& ar )
   {
      ar( tempData );
   }

private:
   struct Person
   {
      std::time_t date{};
      std::string m_name{};
      std::string m_from_city{};
      std::string m_to_city{};
   };

   std::vector<Person> m_people;
};


} // namespace

#endif /* SRC_EXCHANGETJ_H_ */
