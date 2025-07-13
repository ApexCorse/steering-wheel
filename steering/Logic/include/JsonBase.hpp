#ifndef JSONBASE_H
#define JSONBASE_H

#include <tiny_json.h>

class JsonBase {
protected:
  JsonBase(json_t const *json);

  json_t const *json;

  char const *getName();
  json_t const *getPropertyOfType(const char *name, const jsonType_t type);

private:
  static const int MAX_NAME_LENGTH = 256;
  char name[MAX_NAME_LENGTH];
};

#endif
