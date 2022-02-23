#include "parser.h"
#define cout std::cout
#define cin std::cin
#define clear SLCJON002::clear
#define TagStruct SLCJON002::TagStruct

int main(void)
{
  bool breakflag = false;
  char input;
  TagStruct tags;
  for (;;)
  {
    if (!input)
    {
      cout << "r: read and process input file.\np: print all tags.\nd: dump tags and data to file.\nl: list data for a specific tag.\nq: quit\npress r,p,d,l, or q followed by ENTER: ";
      cin >> input;
    }

    clear();

    switch (input)
    {

    case 'r':
      clear();
      cout << "Please enter the name of the file to be parsed: " << std::endl;
      input = 0;
      break;

    case 'p':
      cout << "print tags\n";
      input = 0;
      break;

    case 'd':
      cout << "dump tags\n";
      input = 0;
      break;

    case 'l':
      cout << "list data for tag\n";
      input = 0;
      break;

    case 'q':
      breakflag = true;
      break;
    };
    if (breakflag)
      break;

    cout << "m: access the menu\nq: quit\npress m,q followed by ENTER: ";
    cin >> input;
    switch (input)
    {

    case 'm':
      input = 0;
      break;

    case 'q':
      breakflag = true;
      break;
    };
    clear() if (breakflag) break;
  }
  return 0;
}