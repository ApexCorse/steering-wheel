#ifndef SECTION_H
#define SECTION_H

#include <JsonBase.hpp>
#include <Module.hpp>

class Section : public JsonBase {
public:
  Section();
  Section(json_t const *json);
  static const size_t MAX_MODULES = 16;

  void getModules(Module (&arr)[MAX_MODULES]);
  size_t getNModules();
private:
  Module modules[MAX_MODULES];
  size_t nModules;
};

#endif
