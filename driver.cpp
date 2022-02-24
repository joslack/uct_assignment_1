#include "parser.h"
using SLCJON002::clear;

int main(void)
{
  std::vector<SLCJON002::TagStruct> tags;
  bool breakflag = false;
  char input = 0;
  std::string dirname = "testcases/";
  std::string xml;

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
      xml = SLCJON002::read_file(dirname);
      tags = SLCJON002::parse_xml(xml);
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