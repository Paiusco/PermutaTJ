/**
 *******************************************************************************
 *
 *    File: main.cpp
 *
 *    Project: exchangeTJ
 *
 *    Author: André B. Paiusco
 *******************************************************************************
 */

#include <iostream>
#include <memory>
#include <fstream>

#include "exchangetj.h"

#include "cereal/archives/binary.hpp"

void
help()
{
   std::cout << "Faz toda a explicacao aqui dentro" << std::endl;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

//TODO: apagar a tela quando escolher uma opção
int main()
{
   int choice;
   bool running = true;

   auto tj = std::make_shared<exchangetj::ExchangeTJ>();

   if ( !tj->init() )
   {
      std::cout << "Falha na inicialização, favor corrigir!" << std::endl;
      return EXIT_FAILURE;
   }

   std::ofstream os{};
   cereal::BinaryOutputArchive outputArchive( os );
   os.close();
   os.clear();
   std::ifstream is{};
   cereal::BinaryInputArchive inputArchive(is);
   is.close();
   is.clear();

   while (running)
   {
      std::cout << "******************************************" << std::endl;
      std::cout << " 1 - Procurar por possíves permutas" << std::endl;
      std::cout << " 2 - Adicionar pessoa a lista" << std::endl;
      std::cout << " 3 - Deletar pessoa" << std::endl;
      std::cout << " 4 - Help" << std::endl;
      std::cout << " 5 - Sair" << std::endl;
      std::cout << " Escolha uma das opções acima e de Enter: " << std::endl;
      std::cout << "******************************************" << std::endl;


      std::cin >> choice;
      std::cin.ignore();

      switch (choice)
      {
         case 1:
            std::cout << "Vamos ver se há alguma permuta possível!\n";
            tj->run();
            // rest of code here
            break;
         case 2:
            std::cout << "Entrando em modo de adição de pessoas...\n";
            tj->add_person();
            // rest of code here
            break;
         case 3:
            std::cout << "Entrando em modo de exclusão de pessoas...\n";
            tj->delete_person();
            // rest of code here
            break;
         case 4:
            std::cout << "Vamos explicar cada uma das opções então!\n";
            help();
            // rest of code here
            break;
         case 5:
            std::cout << "Desligando...\n";
            running = false;
            break;
         default:
            std::cout << "Essa escolha não é válida\n";
            std::cout << "Escolha novamente!\n";
            break;
      }

   }
   return EXIT_SUCCESS;
}
