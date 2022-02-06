/**
 *******************************************************************************
 *
 *    File: exchangetj.cpp
 *
 *    Project: exchangeTJ
 *
 *    Author: André B. Paiusco
 *******************************************************************************
 */

#include "exchangetj.h"
#include <iostream>
#include <algorithm>


namespace exchangetj
{

ExchangeTJ::ExchangeTJ()
{

}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

bool
ExchangeTJ::init()
{
   return true;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void
ExchangeTJ::run()
{
  for (auto it = m_people.begin(); it != m_people.end(); ++it)
  {
    for (auto it2 = m_people.begin(); it2 != m_people.end(); ++it)
    {
      if (it->m_to_city == it2->m_from_city)
      {
        if (it->m_from_city == it2->m_to_city)
        {
          std::cout << "Match! Permuta direta\n";
          std::cout << "Entre " << it->m_name << " e " << it2->m_name << '\n';
          continue;
        }

        for (auto it3 = m_people.begin(); it3 != m_people.end(); ++it)
        {
          if (it2->m_to_city == it3->m_from_city)
          {
            if (it->m_from_city == it3->m_to_city)
            {
              std::cout << "Match! Permuta level 2\n";
              std::cout << "Entre " << it->m_name << ", " << it2->m_name
                <<  " e " << it3->m_name << '\n';
              continue;
            }

            for (auto it4 = m_people.begin(); it4 != m_people.end(); ++it)
            {
              if (it2->m_to_city == it4->m_from_city)
              {
                if (it->m_from_city == it4->m_to_city)
                {
                  std::cout << "Match! Permuta level 2\n";
                  std::cout << "Entre " << it->m_name << ", " << it2->m_name
                    <<  " e " << it4->m_name << '\n';
                  continue;
                }

                // for.......
                // https://www.geeksforgeeks.org/find-paths-given-source-destination/
              }
            }
          }
        }
      }
    /* code */
    }
  }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void
ExchangeTJ::add_person()
{
   // system("clear");
   Person p;

   std::cout << "Digite o nome da pessoa que deseja adicionar: \n";
   std::getline(std::cin, p.m_name);

   std::cout << "De que cidade " << p.m_name << " quer sair?\n";
   std::getline(std::cin, p.m_from_city);

   std::cout << "Para qual cidade " << p.m_name << " quer ir?\n";
   std::getline(std::cin, p.m_to_city);

   std::cout << "Cadastro adicionado: \n";
   std::cout << "--------------------------------------------\n";
   std::cout << "Nome: " << p.m_name << std::endl;
   std::cout << "Cidade de saida: " << p.m_from_city << std::endl;
   std::cout << "Cidade que gostaria de ir: " << p.m_to_city <<std::endl;

   m_people.emplace_back(p);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void
ExchangeTJ::delete_person()
{
   // system("clear");
   std::string name_del;
   std::cout << "Digite o nome da pessoa que deseja deletar: \n";
   std::getline(std::cin, name_del);

   for (auto it = m_people.begin(); it != m_people.end(); )
   {
      if ( it->m_name == name_del )
      {
         it = m_people.erase(it);
         std::cout << name_del << "excluído com sucesso!\n";
      } else
      {
         ++it;
      }
   }

}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} //namespace ExchangeTJ
