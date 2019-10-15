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

private:

};


} // namespace

#endif /* SRC_EXCHANGETJ_H_ */