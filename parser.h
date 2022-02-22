#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

namespace SLCJON002
{
  struct TagStruct
  {
    std::string name;
    int num;
    std::string txt;
  };
  void clear(void);
}
#endif
