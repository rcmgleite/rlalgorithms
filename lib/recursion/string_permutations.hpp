#ifndef RL_ALGORITHMS_LIB_RECURSION_STRING_PERMUTATIONS_HPP
#define RL_ALGORITHMS_LIB_RECURSION_STRING_PERMUTATIONS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

namespace recursion
{

using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::vector;

void print(const vector<string> &s)
{
  for (auto &v : s)
  {
    cout << v << endl;
  }
}

/**
 *  O(n) where n = s.size();
 */
string add_char_at(const string &s, char c, unsigned int at)
{
  if (at > s.size())
  {
    throw std::out_of_range("'at' > s.size()");
  }

  stringstream ss;
  for (unsigned int i = 0; i < s.size(); i++)
  {
    if (at == i)
    {
      ss << c;
    }

    ss << s[i];
  }

  if (at == s.size())
  {
    ss << c;
  }

  return ss.str();
}

vector<string> string_permutations(const string &s, unsigned int index, vector<string> &current_result)
{
  if (index >= s.size())
  {
    return current_result;
  }

  vector<string> result;
  for (unsigned int i = 0; i < current_result.size(); i++)
  {

    for (unsigned int j = 0; j <= current_result[i].size(); j++)
    {
      result.push_back(add_char_at(current_result[i], s[index], j));
    }
  }

  return string_permutations(s, index + 1, result);
}

/*
   'abc' -> Generates 6 permutations (3!)

    [
      'abc',
      'acb',
      'bac',
      'bca',
      'cab',
      'cba',
    ]
 */
vector<string> string_permutations(const string &s)
{
  vector<string> result({add_char_at("", s[0], 0)});
  result = string_permutations(s, 1, result);
  return result;
}

}; // namespace recursion

#endif
