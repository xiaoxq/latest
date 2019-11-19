#include "nlohmann/json.hpp"

#include <sstream>
#include <string>

#include "gtest/gtest.h"

namespace latest {
namespace third_party {

TEST(JsonTest, Simple) {
  // Just test if the third-party library is usable.
  std::stringstream ss;
  ss << nlohmann::json::array({1, 2, 3});
  EXPECT_EQ("[1,2,3]", ss.str());
}

}  // namespace third_party
}  // namespace latest
