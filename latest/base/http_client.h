#pragma once

#include <string>

#include "nlohmann/json.hpp"

namespace latest {
namespace base {

class HttpClient {
 public:
  // Post a json to target url, get response as string.
  static bool Post(std::string_view url, const nlohmann::json &json,
                   std::string *result = nullptr);

  // Post a json to target url, get response as json.
  static bool Post(std::string_view url, const nlohmann::json &json,
                   nlohmann::json *result);
};

}  // namespace base
}  // namespace latest
