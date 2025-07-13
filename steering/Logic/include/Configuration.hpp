#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <tiny_json.h>

class Configuration {
public:
    Configuration();
    
    json_t const *getSection(const char *name);
    json_t const *getModule(json_t const *section, const char *name);
    json_t const *getMeasurement(json_t const *module, const char *name);

private:
    static int const MAX_JSON_SIZE = 2048;

    json_t array[MAX_JSON_SIZE];
    json_t const *json;
};

#endif
