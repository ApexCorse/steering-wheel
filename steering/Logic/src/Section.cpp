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

  json_t const *summaries = json_getProperty(json, "summaries");
  if (!summaries || json_getType(summaries) != JSON_ARRAY) return;

  json_t const *currentJsonSummary = json_getChild(summaries);
  if (!currentJsonSummary) return;

  firstSummary = new Summary(currentJsonSummary);
  firstSummary->next = nullptr;
  Summary *currentSummary = firstSummary;
  nSummaries = 1;

  currentJsonSummary = json_getSibling(currentJsonSummary);

  while (currentJsonSummary) {
    Summary *newSummary = new Summary(currentJsonSummary);
    newSummary->next = nullptr;
    currentSummary->next = newSummary;
    currentSummary = newSummary;

    nSummaries++;
    currentJsonSummary = json_getSibling(currentJsonSummary);
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

uint8_t Section::getNSummaries()
{
  return nSummaries;
}

Summary *Section::getFirstSummary()
{
  return firstSummary;
}

Summary *Section::getSummaryByName(const char *name)
{
  uint8_t i = 0;
  Summary *current = firstSummary;

  while (current && i < nModules) {
    if (strcmp(current->getName(), name) == 0)
      return current;

    i++;
    current = current->next;
  }

  return nullptr;
}
