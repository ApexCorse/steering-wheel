#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <tiny_json.h>
#include <Section.hpp>

class Configuration {
public:
    Configuration();
    
    static int const MAX_JSON_SIZE = 2048;
    uint8_t getNSections();
    Section *getFirstSection();
    Section *getSectionByName(const char *name);
private:
    json_t array[MAX_JSON_SIZE];
    json_t const *json;

    // Linked list
    Section *firstSection;
    uint8_t nSections;
};

#endif
