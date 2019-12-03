#include "latest/base/string.h"

#include <vector>

#include "absl/strings/str_cat.h"

namespace latest {
namespace base {
namespace {

static const char kBase64Array[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// A table which maps a char to its value in Base64 mode.
std::vector<int> Base64CodeTable() {
  std::vector<int> table(256, -1);
  const size_t base64_array_length = strlen(kBase64Array);
  for (size_t i = 0; i < base64_array_length; ++i) {
    table[kBase64Array[i]] = static_cast<int>(i);
  }
  return table;
}

std::string Base64Piece(const char in0, const char in1, const char in2) {
  const int triplet = in0 << 16 | in1 << 8 | in2;
  std::string out(4, '=');
  out[0] = kBase64Array[(triplet >> 18) & 0x3f];
  out[1] = kBase64Array[(triplet >> 12) & 0x3f];
  if (in1) {
    out[2] = kBase64Array[(triplet >> 6) & 0x3f];
  }
  if (in2) {
    out[3] = kBase64Array[triplet & 0x3f];
  }
  return out;
}

}  // namespace

std::string DecodeBase64(std::string_view base64_str) {
  static const std::vector<int> kBase64CodeTable = Base64CodeTable();

  std::string bytes;
  // Binary string is generally 3/4 the length of base64 string
  bytes.reserve(base64_str.length() * 3 / 4 + 3);
  unsigned int sum = 0, sum_bits = 0;
  for (const char c : base64_str) {
    if (kBase64CodeTable[c] == -1) {
      break;
    }

    // Convert 6-bits Base64 chars to 8-bits general bytes.
    sum = (sum << 6) + kBase64CodeTable[c];
    sum_bits += 6;
    if (sum_bits >= 8) {
      bytes.push_back(static_cast<char>((sum >> (sum_bits - 8)) & 0xFF));
      sum_bits -= 8;
    }
  }
  return bytes;
}

std::string EncodeBase64(std::string_view in) {
  std::string out;
  if (in.empty()) {
    return out;
  }

  const size_t in_size = in.length();
  out.reserve(((in_size - 1) / 3 + 1) * 4);
  for (size_t i = 0; i + 2 < in_size; i += 3) {
    absl::StrAppend(&out, Base64Piece(in[i], in[i + 1], in[i + 2]));
  }
  if (in_size % 3 == 1) {
    absl::StrAppend(&out, Base64Piece(in[in_size - 1], 0, 0));
  }
  if (in_size % 3 == 2) {
    absl::StrAppend(&out, Base64Piece(in[in_size - 2], in[in_size - 1], 0));
  }
  return out;
}

}  // namespace base
}  // namespace latest
