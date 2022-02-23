#include "parser.h"

void SLCJON002::clear(void) { system("clear"); }

void SLCJON002::print_available_files(std::string directory)
{
  // see https://stackoverflow.com/questions/62409409/how-to-make-stdfilesystemdirectory-iterator-to-list-filenames-in-order
  // for reference
  for (const auto &entry : std::filesystem::directory_iterator(directory))
  {
    std::string name = entry.path().string();
    size_t idx = name.find('/');
    std::cout << "Available Files: \n"
              << name.substr(idx + 1) << std::endl;
  }
}
