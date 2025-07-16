#ifndef SECTION_HPP
#define SECTION_HPP

#include <JsonBase.hpp>
#include <Module.hpp>
#include <Summary.hpp>

class Section : public JsonBase {
public:
  Section();
  Section(json_t const *json);

  Section *next;

  uint8_t getNModules();
  Module *getFirstModule();
  Module *getModuleByName(const char *name);

  uint8_t getNSummaries();
  Summary *getFirstSummary();
  Summary *getSummaryByName(const char *name);
private:
  // Linked list
  Module *firstModule;
  uint8_t nModules;

  // Linked list
  Summary *firstSummary;
  uint8_t nSummaries;
};

#endif
