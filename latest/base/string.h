#pragma once

#include <string>

#include "absl/strings/string_view.h"

namespace latest {
namespace base {

std::string DecodeBase64(absl::string_view base64_str);
std::string EncodeBase64(absl::string_view str);

}  // namespace base
}  // namespace latest
