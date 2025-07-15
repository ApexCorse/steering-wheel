#include <Module.hpp>
#include <cstring>

Module::Module() {}

Module::Module(json_t const *json): JsonBase(json) 
{
  json_t const *measurements = json_getProperty(json, "measurements");
  if (!measurements || json_getType(measurements) != JSON_ARRAY) return;

  json_t const *currentJsonMeasurement = json_getChild(measurements);
  if (!currentJsonMeasurement) return;

  firstMeasurement = new Measurement(currentJsonMeasurement);
  firstMeasurement->next = nullptr;
  Measurement *currentMeasurement = firstMeasurement;
  nMeasurements = 1;

  currentJsonMeasurement = json_getSibling(currentJsonMeasurement);

  while (currentJsonMeasurement) {
    Measurement *newMeasurement = new Measurement(currentJsonMeasurement);
    newMeasurement->next = nullptr;
    currentMeasurement->next = newMeasurement;
    currentMeasurement = newMeasurement;

    nMeasurements++;
    currentJsonMeasurement = json_getSibling(currentJsonMeasurement);
  }
}

uint8_t Module::getNMeasurements() 
{
  return nMeasurements;
}

Measurement *Module::getFirstMeasurement()
{
  return firstMeasurement;
}

Measurement *Module::getMeasurementByName(const char *name)
{
  uint8_t i = 0;
  Measurement *current = firstMeasurement;

  while (current && i < nMeasurements) {
    if (strcmp(current->getName(), name) == 0)
      return current;

    i++;
    current = current->next;
  }

  return nullptr;
}
