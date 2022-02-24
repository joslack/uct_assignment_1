#include "parser.h"
#include <experimental/filesystem>
void SLCJON002::clear(void) { system("clear"); }

void SLCJON002::read_file(std::string dirname)
{
  std::string name;
  std::ifstream in;
  std::string xml;

  std::cout << "Please enter the name of the file to be parsed: ";
  std::cin >> name;
  // open file
  std::string filename = dirname + name;
  in.open(filename);
  // ensure valid filename
  while (!in)
  {
    std::cout << "Please enter a valid filename: ";
    std::cin >> name;
    filename = dirname + name;
    in.open(filename);
  }
  //
  std::ostringstream strstream;
  strstream << in.rdbuf();
  xml = strstream.str();
  in.close();

  std::cout << xml << std::endl;
  std::cout << "Press c followed by ENTER to continue: ";
  char c;
  std::cin >> c;
  SLCJON002::clear();
  return xml;
}