#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <filesystem>
#include <fstream>

namespace SLCJON002
{
  struct TagStruct
  {
    std::string name;
    int num;
    std::string txt;
  };
  void clear(void);

  void read_file(std::string dirname);

  // TODO
  void print_tags(std::vector<TagStruct>);
  void dump_tags(std::vector<TagStruct>);
  void list(std::string tag, std::vector<TagStruct>);
}
#endif
