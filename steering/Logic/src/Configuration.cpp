#include <Configuration.hpp>
#include <json_config.h>
#include <cstring>

Configuration::Configuration()
{
  json = json_create(json_config_json, array, 2048);

  json_t const *sections = json_getProperty(json, "sections");
  if (!sections || json_getType(sections) != JSON_ARRAY) return;

  json_t const *currentJsonSection = json_getChild(sections);
  while (currentJsonSection) {
    this->sections[nSections++] = Section(currentJsonSection);

    currentJsonSection = json_getSibling(currentJsonSection);
  }
}

uint8_t Configuration::getNSections()
{
  return nSections;
}

Section *Configuration::getSections()
{
  return sections;
}

Section *Configuration::getSectionByName(const char *name)
{
  for (uint8_t i = 0; i < nSections; i++) {
    Section *current = sections + i;
    if (strcmp(current->getName(), name) == 0)
      return current;
  }
  
  return nullptr;
}
