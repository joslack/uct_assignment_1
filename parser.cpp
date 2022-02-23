#include "parser.h"

void SLCJON002::clear(void) { system("clear"); }
void SLCJON002::print_available_files(std::string directory)
{
  for (const auto &entry : std::filesystem::directory_iterator(directory))
  {
    std::cout << entry.path() << std::endl;
  }
}
