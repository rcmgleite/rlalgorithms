
#ifndef RL_ALGORITHMS_LIB_RECURSION_ALL_VALID_PARENTHESES_HPP
#define RL_ALGORITHMS_LIB_RECURSION_ALL_VALID_PARENTHESES_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>

namespace recursion
{
using std::cout;
using std::endl;
using std::set;
using std::string;
using std::stringstream;

void print(set<string> s)
{
  for (auto &ss : s)
  {
    cout << ss << endl;
  }
}

string add_parentheses_at(const string &s, unsigned int at)
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
      ss << "()";
    }

    ss << s[i];
  }

  if (at == s.size())
  {
    ss << "()";
  }

  return ss.str();
}

set<string> all_valid_parentheses(int n, set<string> &current, int index)
{
  if (index > n)
  {
    return current;
  }

  set<string> result;

  for (auto &s : current)
  {
    for (unsigned int i = 0; i <= s.size(); i++)
    {
      result.insert(add_parentheses_at(s, i));
    }
  }

  return all_valid_parentheses(n, result, index + 1);
}

set<string> all_valid_parentheses(int n)
{
  set<string> s;
  if (n == 0)
  {
    return s;
  }

  s.insert("()");
  return all_valid_parentheses(n, s, 2);
}

} // namespace recursion

#endif
