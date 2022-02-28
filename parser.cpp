#include "parser.h"
void SLCJON002::clear(void) { system("clear"); }

std::string SLCJON002::read_file(std::string dirname)
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
  std::ostringstream strstream;
  // convert to strstream
  strstream << in.rdbuf();
  // convert to string
  xml = strstream.str();
  in.close();
  return xml;
}

std::vector<SLCJON002::TagStruct> SLCJON002::parse_xml(std::string xml)
{
  std::vector<size_t> open_idx;
  std::vector<size_t> close_idx;
  std::string tag;
  std::string txt;
  std::stack<std::string> tagStack;
  std::stack<std::string> txt_stack;
  std::vector<SLCJON002::TagStruct> tags;

  for (size_t i = 0; i < xml.length(); i++)
  {
    // check for open bracket
    if (xml[i] == '<')
    {
      open_idx.push_back(i);
      // gather tag in between brackets
      ++i;
      while (xml[i] != '>')
      {

        // edge case where string happens to contain an open carrot
        if (xml[i] == '<')
        {
          open_idx.pop_back();
          open_idx.push_back(i);
          tag = "";
        }
        // otherwise record tag and move idx
        else
        {
          tag = tag + xml[i];
        }
        ++i;
      }
      close_idx.push_back(i + 1);
      if (!tagStack.size())
        tagStack.push(tag);
      if (tag.substr(1) == tagStack.top())
      {
        std::cout << tagStack.top() << ": ";
        std::cout << txt_stack.top() << std::endl;
        tagStack.pop();
        txt_stack.pop();
      }
      else
        tagStack.push(tag);
      txt_stack.push(txt);
      tag = "";
      txt = "";
    }
  }
  size_t o_idx = 1;
  size_t c_idx = 0;
  while (o_idx < close_idx.size())
  {
    std::cout << xml.substr(close_idx[c_idx], open_idx[o_idx] - close_idx[c_idx]);
    ++o_idx;
    ++c_idx;
  }
  std::cout << "Press c followed by ENTER to continue: ";
  char c;
  std::cin >> c;
  SLCJON002::clear();
  return tags;
}