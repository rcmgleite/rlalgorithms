#ifndef RL_ALGORITHMS_DP_LCS
#define RL_ALGORITHMS_DP_LCS

#include <string>

namespace dp
{
using std::string;

/* 
 * "AGGTAB” and “GXTXAYB" -> "GTAB"
 */
int lcs_length(const string& s1, const string& s2);
int lcs_length(const string& s1, const string& s2, int s1p, int s2p);

int lcs_length(const string& s1, const string& s2)
{
  return lcs_length(s1, s2, 0, 0);
}

int lcs_length(const string& s1, const string& s2, int s1p, int s2p) {
  if (s1p == (int)s1.size() || s2p == (int)s2.size()) {
    return 0;
  }

  if (s1[s1p] == s2[s2p]) {
    return 1 + lcs_length(s1, s2, s1p + 1, s2p + 1);
  }

  return std::max(lcs_length(s1, s2, s1p + 1, s2p), lcs_length(s1, s2, s1p, s2p + 1));
}

}

#endif