#ifndef JSONBASE_HPP 
#define JSONBASE_HPP

#include <tiny_json.h>

class JsonBase {
public:
  char const *getName();
protected:
  JsonBase();
  JsonBase(json_t const *json);

  json_t const *json;

  json_t const *getPropertyOfType(const char *name, const jsonType_t type);

private:
  static const uint8_t MAX_NAME_LENGTH = 128;
  char name[MAX_NAME_LENGTH];
};

#endif
