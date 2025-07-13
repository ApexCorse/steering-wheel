#include <Section.hpp>

Section::Section(json_t const *json): JsonBase(json), nModules(0) {
  json_t const *modules = getPropertyOfType("modules", JSON_ARRAY);

  if (!modules) return;

  json_t const *current = modules;
  while (current && nModules < MAX_MODULES) {
    Module newModule(current);
    (this->modules)[nModules] = newModule;

    nModules++;
    current = json_getSibling(current);
  }
}

void Section::getModules(Module (&arr)[MAX_MODULES]) {
  for (size_t i = 0; i < nModules; i++) {
    arr[i] = modules[i];
  }
}

size_t Section::getNModules() {
  return nModules;
}
