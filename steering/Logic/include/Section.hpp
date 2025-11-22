#ifndef SECTION_HPP
#define SECTION_HPP

#include <JsonBase.hpp>
#include <Module.hpp>
#include <Summary.hpp>

#define CONFIGURATION_MAX_MODULES 8

class Section : public JsonBase {
public:
  Section();
  Section(json_t const *json);

  uint8_t getNModules();
  Module *getModules();
  Module *getModuleByName(const char *name);

  uint8_t getNSummaries();
  Summary *getSummaries();
  Summary *getSummaryByName(const char *name);
private:
  // Linked list
  Module modules[CONFIGURATION_MAX_MODULES];
  uint8_t nModules;

  // Linked list
  Summary *summaries;
  uint8_t nSummaries;
};

#endif
