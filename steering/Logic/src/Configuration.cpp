#include <Configuration.hpp>
#include <json_config.h>
#include <cstring>

Configuration::Configuration()
{
  json = json_create(json_config_json, array, 2048);

  json_t const *sections = json_getProperty(json, "sections");
  if (!sections || json_getType(sections) != JSON_ARRAY) return;

  json_t const *currentJsonSection = json_getChild(sections);
  if (!currentJsonSection) return;

  firstSection = new Section(currentJsonSection);
  firstSection->next = nullptr;
  Section *currentSection = firstSection;
  nSections = 1;

  currentJsonSection = json_getSibling(currentJsonSection);

  while (currentJsonSection) {
    Section *newSection = new Section(currentJsonSection);
    newSection->next = nullptr;
    currentSection->next = newSection;
    currentSection = newSection;

    nSections++;
    currentJsonSection = json_getSibling(currentJsonSection);
  }
}

uint8_t Configuration::getNSections()
{
  return nSections;
}

Section *Configuration::getFirstSection()
{
  return firstSection;
}

Section *Configuration::getSectionByName(const char *name)
{
  uint8_t i = 0;
  Section *current = firstSection;

  while (current && i < nSections) {
    if (strcmp(current->getName(), name) == 0)
      return current;

    i++;
    current = current->next;
  }
  
  return nullptr;
}
