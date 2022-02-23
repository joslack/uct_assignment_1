#include "parser.h"

int main(void)
{
  bool breakflag = false;
  char input;
  for (;;)
  {
    if (!input)
    {
      std::cout << "r: read and process input file.\np: print all tags.\nd: dump tags and data to file.\nl: list data for a specific tag.\nq: quit\npress r,p,d,l, or q followed by ENTER: ";
      std::cin >> input;
    }

    SLCJON002::clear();

    switch (input)
    {
    case 'r':
      std::cout << "read file\n";
      input = 0;
      break;
    case 'p':
      std::cout << "print tags\n";
      input = 0;
      break;
    case 'd':
      std::cout << "dump tags\n";
      input = 0;
      break;
    case 'l':
      std::cout << "list data for tag\n";
      input = 0;
      break;
    case 'q':
      breakflag = true;
      break;
    };
    if (breakflag)
      break;
    std::cout << "m: access the menu\nq: quit\npress m,q followed by ENTER: ";
    std::cin >> input;
    switch (input)
    {
    case 'm':
      input = 0;
      break;
    case 'q':
      breakflag = true;
      break;
    };
    SLCJON002::clear();

    if (breakflag)
      break;
  }
  return 0;
}