#pragma once

#include <string>

#include "google/protobuf/message.h"

namespace latest {
namespace base {

std::string DecodeBase64(std::string_view base64_str);
std::string EncodeBase64(std::string_view str);

struct ProtoFormatter {
  inline void operator()(std::string* out,
                         const google::protobuf::Message& msg) const {
    out->append(msg.DebugString());
  }
};

}  // namespace base
}  // namespace latest
