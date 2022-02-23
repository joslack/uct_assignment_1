#include "parser.h"

void SLCJON002::clear(void) { system("clear"); }

void SLCJON002::print_available_files(std::string directory)
{
  /**
   * takes the name of directory and prints the available files to the command line
   *
   * see https://stackoverflow.com/questions/62409409/how-to-make-stdfilesystemdirectory-iterator-to-list-filenames-in-order
   * for reference
   */
  std::cout << "Available Files:" << std::endl;
  for (const auto &entry : std::filesystem::directory_iterator(directory))
  {
    std::string name = entry.path().string(); // convert filesystem_entry to string
    size_t idx = name.find('/');
    std::cout << name.substr(idx + 1) << std::endl;
  }
}
