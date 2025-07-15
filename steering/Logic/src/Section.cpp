#include <Section.hpp>
#include <cstring>

Section::Section() {}

Section::Section(json_t const *json): JsonBase(json), nModules(0) 
{
  json_t const *modules = json_getProperty(json, "modules");
  if (!modules || json_getType(modules) != JSON_ARRAY) return;

  json_t const *currentJsonModule = json_getChild(modules);
  if (!currentJsonModule) return;

  firstModule = new Module(currentJsonModule);
  firstModule->next = nullptr;
  Module *currentModule = firstModule;
  nModules = 1;

  currentJsonModule = json_getSibling(currentJsonModule);

  while (currentJsonModule) {
    Module *newModule = new Module(currentJsonModule);
    newModule->next = nullptr;
    currentModule->next = newModule;
    currentModule = newModule;

    nModules++;
    currentJsonModule = json_getSibling(currentJsonModule);
  }
}

uint8_t Section::getNModules() 
{
  return nModules;
}

Module *Section::getFirstModule()
{
  return firstModule;
}

Module *Section::getModuleByName(const char *name)
{
  uint8_t i = 0;
  Module *current = firstModule;

  while (current && i < nModules) {
    if (strcmp(current->getName(), name) == 0)
      return current;

    i++;
    current = current->next;
  }

  return nullptr;
}
