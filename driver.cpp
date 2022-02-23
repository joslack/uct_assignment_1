#include "parser.h"
#include <iostream>
using SLCJON002::clear;
using SLCJON002::TagStruct;

int main(void)
{
  bool breakflag = false;
  char input = 0;
  std::string name;
  std::string dirname;
  std::string filename;

  for (;;)
  {
    if (!input)
    {
      std::cout << "r: read and process input file.\np: print all tags.\nd: dump tags and data to file.\nl: list data for a specific tag.\nq: quit\npress r,p,d,l, or q followed by ENTER: ";
      std::cin >> input;
    }

    clear();

    switch (input)
    {

    case 'r':
      clear();

      dirname = "testcases/";
      SLCJON002::print_available_files(dirname);

      std::cout << "Please enter the name of the file to be parsed: ";

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
    clear();
    if (breakflag)
      break;
  }
  return 0;
}