#include <cstring>
#include <JsonBase.hpp>

JsonBase::JsonBase() {}

JsonBase::JsonBase(json_t const *json): json(json) {
  json_t const *nameJson = getPropertyOfType("name", JSON_TEXT);
  if (!nameJson) return;

  char const* name = json_getValue(nameJson);
  strncpy(this->name, name, MAX_NAME_LENGTH);
}

json_t const *JsonBase::getPropertyOfType(const char *name, const jsonType_t type) {
  json_t const *res = json_getProperty(json, name);
  if (!res || json_getType(res) != type) return nullptr;

  return res;
}

char const *JsonBase::getName() {
  return name;
}
