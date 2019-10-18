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
#include <fstream>



namespace exchangetj
{

ExchangeTJ::ExchangeTJ()
{

}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

ExchangeTJ::~ExchangeTJ()
{
   std::ofstream file("teste.txt");

   for (auto &&i : m_people)
   {
      file.write(reinterpret_cast<char*>(&i), sizeof(Person));
   }

   file.close();
   std::cout << "pos escrever no arquivo" << std::endl;

}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

bool
ExchangeTJ::init()
{
   //TODO: Not working yet.Think on boost::serialization or cereal
   std::ifstream file("teste.txt");

   long size;

   file.read(reinterpret_cast<char*>(&size), sizeof(long));
   m_people.resize(size);

   for(int i = 0;i < size;++i)
   {
      Person p;
      file.read(reinterpret_cast<char*>(&p), sizeof(Person));
      m_people.emplace_back(p);
   }
   file.close();


   for (auto &&i : m_people)
   {
      std::cout << "nome: " << i.m_name << std::endl;
      std::cout << "from: " << i.m_from_city << std::endl;
      std::cout << "to: " << i.m_to_city << std::endl;
   }

   return true;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void
ExchangeTJ::run()
{

}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void
ExchangeTJ::add_person()
{
   system("clear");
   Person p;

   std::cout << "Digite o nome da pessoa que deseja adicionar: " << std::endl;
   std::getline(std::cin, p.m_name);

   std::cout << "De que cidade " << p.m_name << " quer sair?" << std::endl;
   std::getline(std::cin, p.m_from_city);

   std::cout << "Para qual cidade " << p.m_name << " quer ir?" << std::endl;
   std::getline(std::cin, p.m_to_city);

   std::cout << "Cadastro adicionado: " << std::endl;
   std::cout << "--------------------------------------------" << std::endl;
   std::cout << "Nome: " << p.m_name << std::endl;
   std::cout << "Cidade de saida: " << p.m_from_city << std::endl;
   std::cout << "Cidade que gostaria de ir: " << p.m_to_city <<std::endl;

   m_people.emplace_back(p);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void
ExchangeTJ::delete_person()
{
   system("clear");
   std::string name_del;
   std::cout << "Digite o nome da pessoa que deseja deletar: " << std::endl;
   std::getline(std::cin, name_del);

   for (auto it = m_people.begin(); it != m_people.end(); )
   {
      if ( it->m_name == name_del )
      {
         it = m_people.erase(it);
         std::cout << name_del << "excluído com sucesso!" << std::endl;
      } else
      {
         ++it;
      }
   }

}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} //namespace ExchangeTJ