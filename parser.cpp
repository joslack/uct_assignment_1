#include "parser.h"
void SLCJON002::clear(void) { system("clear"); }

void SLCJON002::print_tag_struct(SLCJON002::TagStruct tagstruct)
{
  std::cout << "TagStruct{" + tagstruct.name << ", " << tagstruct.num << ", " << tagstruct.txt + "}" << std::endl;
}

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

  std::string tag = "";
  std::string txt = "";
  std::stack<std::string> tagStack;
  std::stack<std::string> txtStack;
  std::vector<SLCJON002::TagStruct> tags;
  SLCJON002::TagStruct tag_struct;

  for (size_t i = 0; i < xml.length(); i++)
  {
    if ((xml[i] == '<') && (xml[i + 1] != ' '))
    {
      // gather tag in between brackets
      ++i;
      while (xml[i] != '>')
      {
        tag = tag + xml[i];
        ++i;
      }
      // add tag to stack
      if (tagStack.empty() || (tagStack.top() != tag.substr(1)))
        tagStack.push(tag);
      else
      {
        // check if tag close
        if (tagStack.top() == tag.substr(1))
        {
          // ensure that there are not duplicate tags
          bool dupe = false;
          for (auto i = 0; i < tags.size(); i++)
          {
            if (tags[i].name == tagStack.top())
            {
              tags[i].txt = tags[i].txt + ":" + txtStack.top();
              tags[i].num++;
              dupe = true;
            }
          }
          if (!dupe)
          {
            tag_struct = {tagStack.top(), 1, txtStack.top()};
            tags.push_back(tag_struct);
          }
          tagStack.pop();
          txtStack.pop();
        }
      }
      // gather text after tag
      ++i;
      while (xml[i] != '<' || (xml[i] == '<' && xml[i + 1] == ' '))
      {
        txt = txt + xml[i];
        ++i;
      }
      --i;
      if (xml[i + 2] == '/')
        txtStack.push(txt);
      else
      {
        for (auto j = 0; j < tags.size(); j++)
        {
          if (tag == tags[j].name)
          {
            if (tags[j].txt == "")
              tags[j].txt = txt;
            else
              tags[j].txt = tags[j].txt + ":" + txt;
            tags[j].num += 1;
          }
        }
      }
      txt = "";
      tag = "";
    }
  }

  SLCJON002::clear();
  return tags;
}

void SLCJON002::list(std::string tag, std::vector<SLCJON002::TagStruct> tags)
{
  for (auto i : tags)
  {
    if (i.name == tag)
    {
      print_tag_struct(i);
    }
  }
}