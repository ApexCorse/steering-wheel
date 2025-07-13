#include <Configuration.hpp>
#include <json_config.h>

Configuration::Configuration()
{
  json = json_create(json_config_json, array, 2048);
}

json_t const *Configuration::getSection(const char *name) {
  json_t const *sections = json_getProperty(json, "sections");
  if (!sections) return nullptr;

  json_t const *section = json_getProperty(sections, name);
  if (!section || json_getType(section) != JSON_OBJ) 
    return nullptr;

  return section;
}

json_t const *Configuration::getModule(json_t const *section, const char *name) {
  if (!section) return nullptr;

  json_t const *module_json = json_getProperty(section, name);
  if (!module_json || json_getType(module_json) != JSON_OBJ)
    return nullptr;

  return module_json;
}

json_t const *Configuration::getMeasurement(json_t const *module, const char *name) {
  if (!module) return nullptr;

  json_t const *measurement = json_getProperty(module, name);
  if (!measurement || json_getType(measurement) != JSON_OBJ)
    return nullptr;

  return measurement;
}
