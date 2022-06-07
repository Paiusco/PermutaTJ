#include "menu.h"

#include <iostream>

namespace exchangetj
{

Menu::Menu(std::istream& input, std::ostream& output)
  : m_input(input), m_output(output)
{
  
}

void Menu::main_menu()
{
  int choice;
  m_output << "******************************************\n";
  m_output << " 1 - Procurar por possíves permutas\n";
  m_output << " 2 - Adicionar pessoa a lista\n";
  m_output << " 3 - Deletar pessoa\n";
  m_output << " 4 - Help\n";
  m_output << " 5 - Sair\n";
  m_output << " Escolha uma das opções acima e de Enter: \n";
  m_output << "******************************************\n";

  m_input >> choice;
  m_input.ignore();

  switch (choice)
  {
    case 1:
      m_output << "Vamos ver se há alguma permuta possível!\n";
      // tj->run();
      // rest of code here
      break;
    case 2:
      m_output << "Entrando em modo de adição de pessoas...\n";
      // tj->add_person();
      // rest of code here
      break;
    case 3:
      m_output << "Entrando em modo de exclusão de pessoas...\n";
      // tj->delete_person();
      // rest of code here
      break;
    case 4:
      m_output << "Vamos explicar cada uma das opções então!\n";
      // help();
      // rest of code here
      break;
    case 5:
      m_output << "Desligando...\n";
      // running = false;
      break;
    default:
      m_output << "Essa escolha não é válida\n";
      m_output << "Escolha novamente!\n";
      break;
  }
}

} // namespace exchangeTJ
