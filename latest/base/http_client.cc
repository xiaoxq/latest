#include "latest/base/http_client.h"

#include <sstream>

#include "curlpp/Easy.hpp"
#include "curlpp/Exception.hpp"
#include "curlpp/Options.hpp"
#include "curlpp/cURLpp.hpp"
#include "glog/logging.h"

namespace latest {
namespace base {

using Json = nlohmann::json;

bool HttpClient::Post(std::string_view url, const Json &json,
                      std::string *result) {
  try {
    curlpp::Cleanup cleaner;
    curlpp::Easy request;
    std::ostringstream response;

    request.setOpt(new curlpp::options::Url(url.data()));
    request.setOpt(
        new curlpp::options::HttpHeader({"Content-Type: application/json"}));
    const std::string data = json.dump();
    request.setOpt(new curlpp::options::PostFields(data));
    request.setOpt(new curlpp::options::PostFieldSize(data.length()));
    request.setOpt(new curlpp::options::WriteStream(&response));

    // Perform request and get response string.
    request.perform();
    if (result != nullptr) {
      *result = response.str();
    }
  } catch (curlpp::LogicError &e) {
    LOG(ERROR) << e.what();
    return false;
  } catch (curlpp::RuntimeError &e) {
    LOG(ERROR) << e.what();
    return false;
  }

  return true;
}

bool HttpClient::Post(std::string_view url, const Json &json, Json *result) {
  std::string response;
  if (Post(url, json, &response)) {
    try {
      *result = Json::parse(response.begin(), response.end());
    } catch (...) {
      return false;
    }
  }
  return true;
}

}  // namespace base
}  // namespace latest
