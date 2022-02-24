#include "parser.h"
#include <experimental/filesystem>
void SLCJON002::clear(void) { system("clear"); }

void SLCJON002::read_file(std::string dirname)
{
  std::string name;
  std::ifstream in;
  std::string line;
  std::vector<std::string> lines;

  std::cout << "Please enter the name of the file to be parsed: ";
  std::cin >> name;
  std::string filename = dirname + name;
  in.open(filename);
  while (!in)
  {
    std::cout << "Please enter a valid filename: ";
    std::cin >> name;
    filename = dirname + name;
    in.open(filename);
  }

  while (std::getline(in, line))
  {
    lines.push_back(line);
  }
  in.close();

  for (auto item : lines)
  {
    std::cout << item << std::endl;
  }
  std::cout << "Press c followed by ENTER to continue: ";
  char c;
  std::cin >> c;
  SLCJON002::clear();
}