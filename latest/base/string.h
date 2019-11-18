#pragma once

#include <string>

namespace latest {
namespace base {

std::string DecodeBase64(std::string_view base64_str);
std::string EncodeBase64(std::string_view str);

}  // namespace base
}  // namespace latest
