#include <Section.hpp>
#include <cstring>

Section::Section() {}

Section::Section(json_t const *json): JsonBase(json), nModules(0) 
{
  json_t const *modules = json_getProperty(json, "modules");
  if (!modules || json_getType(modules) != JSON_ARRAY) return;

  json_t const *currentJsonModule = json_getChild(modules);
  while (currentJsonModule) {
    this->modules[nModules++] = Module(currentJsonModule);

    currentJsonModule = json_getSibling(currentJsonModule);
  }

  json_t const *summaries = json_getProperty(json, "summaries");
  if (!summaries || json_getType(summaries) != JSON_ARRAY) return;

  json_t const *currentJsonSummary = json_getChild(summaries);
  while (currentJsonSummary) {
    this->summaries[nSummaries++] = Summary(currentJsonSummary);

    currentJsonSummary = json_getSibling(currentJsonSummary);
  }
}

uint8_t Section::getNModules() 
{
  return nModules;
}

Module *Section::getModules()
{
  return modules;
}

Module *Section::getModuleByName(const char *name)
{
  for (int i = 0; i < nModules; i ++) {
    Module *current = modules + i;
    if (strcmp(current->getName(), name) == 0)
      return current;
  }

  return nullptr;
}

uint8_t Section::getNSummaries()
{
  return nSummaries;
}

Summary *Section::getSummaries()
{
  return summaries;
}

Summary *Section::getSummaryByName(const char *name)
{
  for (int i = 0; i < nSummaries; i++) {
    Summary *current = summaries + i;
    if (strcmp(current->getName(), name) == 0)
      return current;
  }

  return nullptr;
}
