#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <tiny_json.h>
#include <Section.hpp>

#define CONFIGURATION_MAX_SECTIONS 4

class Configuration {
public:
    static Configuration* instance() {
        static Configuration configuration;
        return &configuration;
    }
    
    static int const MAX_JSON_SIZE = 2048;
    uint8_t getNSections();
    Section *getSections();
    Section *getSectionByName(const char *name);
private:
    Configuration();
    json_t array[MAX_JSON_SIZE];
    json_t const *json;

    // Linked list
    Section sections[CONFIGURATION_MAX_SECTIONS];
    uint8_t nSections;
};

#endif
