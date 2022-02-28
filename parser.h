#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <stack>

namespace SLCJON002
{
  struct TagStruct
  {
    std::string name;
    int num;
    std::string txt;
  };
  void clear(void);

  std::string read_file(std::string dirname);
  std::vector<TagStruct> parse_xml(std::string xml);
  // TODO
  void print_tags(std::vector<TagStruct>);
  void dump_tags(std::vector<TagStruct>);
  void list(std::string tag, std::vector<TagStruct>);
}
#endif
