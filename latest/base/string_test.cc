#include "latest/base/string.h"

#include "absl/strings/str_join.h"
#include "gtest/gtest.h"
#include "latest/base/simple_test.pb.h"

namespace latest {
namespace base {

TEST(StringTest, DecodeBase64) {
  EXPECT_EQ("", DecodeBase64(""));
  EXPECT_EQ("f", DecodeBase64("Zg=="));
  EXPECT_EQ("fo", DecodeBase64("Zm8="));
  EXPECT_EQ("foo", DecodeBase64("Zm9v"));
  EXPECT_EQ("foob", DecodeBase64("Zm9vYg=="));
  EXPECT_EQ("fooba", DecodeBase64("Zm9vYmE="));
  EXPECT_EQ("foobar", DecodeBase64("Zm9vYmFy"));
}

TEST(StringTest, EncodeBase64) {
  EXPECT_EQ("", EncodeBase64(""));
  EXPECT_EQ("Zg==", EncodeBase64("f"));
  EXPECT_EQ("Zm8=", EncodeBase64("fo"));
  EXPECT_EQ("Zm9v", EncodeBase64("foo"));
  EXPECT_EQ("Zm9vYg==", EncodeBase64("foob"));
  EXPECT_EQ("Zm9vYmE=", EncodeBase64("fooba"));
  EXPECT_EQ("Zm9vYmFy", EncodeBase64("foobar"));
}

TEST(StringTest, ProtoFormatter) {
  std::vector<SimpleTest> messages(2);
  messages[0].set_int_field(5);
  messages[1].set_string_field("test");
  EXPECT_EQ("int_field: 5\n;string_field: \"test\"\n",
            absl::StrJoin(messages, ";", ProtoFormatter()));
}

}  // namespace base
}  // namespace latest
