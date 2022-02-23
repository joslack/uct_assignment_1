#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <filesystem>

namespace SLCJON002
{
  struct TagStruct
  {
    std::string name;
    int num;
    std::string txt;
  };
  void clear(void);

  void print_available_files(std::string directory);

  std::vector<TagStruct> read_file(std::vector<std::string> filename);
  void print_tags(std::vector<TagStruct> tags);
  void dump_tags(std::vector<TagStruct> tags);
  void list(std::string tag, std::vector<TagStruct> tags);
}
#endif
