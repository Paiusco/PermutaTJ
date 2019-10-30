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

#include "exchangetj.h"
#include <fstream>

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

   while ( running )
   {
      std::cout << "******************************************" << std::endl;
      std::cout << " 1 - Procurar por possíves permutas" << std::endl;
      std::cout << " 2 - Adicionar pessoa a lista" << std::endl;
      std::cout << " 3 - Deletar pessoa" << std::endl;
      std::cout << " 4 - Help" << std::endl;
      std::cout << " 5 - Sair (por exemplo sem salvar)" << std::endl;
      std::cout << " 6 - (temp) Salvar em arquivo" << std::endl;
      std::cout << " 7 - (temp) Carregar de arquivo" << std::endl;
      std::cout << " 8 - Alterar tempData" << std::endl;
      std::cout << " Escolha uma das opções acima e de Enter: " << std::endl;
      std::cout << "******************************************" << std::endl;


      std::cin >> choice;
      std::cin.ignore();

      switch ( choice )
      {
         case 1:
            std::cout << "Vamos ver se há alguma permuta pronta!" << std::endl;
            // rest of code here
            break;
         case 2:
            std::cout << "Entrando em modo de adição de pessoas..."
               << std::endl;
            tj->add_person();
            // rest of code here
            break;
         case 3:
            std::cout << "Entrando em modo de exclusão de pessoas..."
               << std::endl;
            tj->delete_person();
            // rest of code here
            break;
         case 4:
            std::cout << "Vamos explicar cada uma das opções então!"
               << std::endl;
            help();
            // rest of code here
            break;
         case 5:
            system("clear");
            std::cout << "Desligando..." << std::endl;
            running = false;
            break;
         case 6:
           // sample cereal binary saving
           os.open("my_binary_archive.etj", std::ios::binary);
           outputArchive( *tj );
           os.close();
           os.clear();
           std::cout << "tempData saved to disk with value: " << tj->tempData << std::endl;
           break;
         case 7:
           // sample cereal binary loading
           is.open("my_binary_archive.etj", std::ios::binary);
           inputArchive( *tj );
           is.close();
           is.clear();
           std::cout << "tempData loaded from disk with value: " << tj->tempData << std::endl;
           break;
         case 8:
           std::cout << "Digite um novo integer para o novo valor de tempData:" << std::endl;
           std::cin >> tj->tempData;
           std::cout << "Novo valor de tempData(na~o salvo):" << tj->tempData << std::endl;
           break;
         default:
            std::cout << "Essa escolha não é válida" << std::endl;
            std::cout << "Escolha novamente!" << std::endl;
            break;
      }

   }
   return EXIT_SUCCESS;
}
