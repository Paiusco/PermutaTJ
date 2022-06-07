#ifndef SRC_MENU_H_
#define SRC_MENU_H_

#include <iostream>
namespace exchangetj
{

class Menu
{
public:
  Menu(std::istream& input = std::cin, std::ostream& output = std::cout);
  
  void main_menu();
  
private:
  std::istream& m_input;
  std::ostream& m_output;
};

} // namespace exchangeTJ

#endif /* SRC_MENU_H_ */