#include "gtest/gtest.h"
#include <string>
#include <vector>
#include "../../lib/recursion/paint_fill.hpp"

namespace unit_tests
{
using namespace std;
using namespace recursion;

TEST(RECURSION, PAINT_FILL_1)
{
  const int R = Color::R;
  const int G = Color::G;
  const int B = Color::B;
  recursion::screen_t s = screen_t({
      {R, R, R, R, R, R},
      {R, G, G, R, R, G},
      {R, G, G, R, R, R},
      {R, G, G, G, R, R},
      {R, R, R, G, R, R},
      {R, R, R, R, R, R},
  });

  recursion::screen_t expected_result = screen_t({
      {R, R, R, R, R, R},
      {R, B, B, R, R, G},
      {R, B, B, R, R, R},
      {R, B, B, B, R, R},
      {R, R, R, B, R, R},
      {R, R, R, R, R, R},
  });

  recursion::paint_fill(s, 1, 1, B);
  EXPECT_TRUE(recursion::screen_compare(s, expected_result));
}

} // namespace unit_tests