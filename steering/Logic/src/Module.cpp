#include <Module.hpp>
#include <cstring>

Module::Module() {}

Module::Module(json_t const *json): JsonBase(json) 
{
  json_t const *measurements = json_getProperty(json, "measurements");
  if (!measurements || json_getType(measurements) != JSON_ARRAY) return;

  json_t const *currentJsonMeasurement = json_getChild(measurements);

  while (currentJsonMeasurement) {
    this->measurements[nMeasurements++] = Measurement(currentJsonMeasurement);

    currentJsonMeasurement = json_getSibling(currentJsonMeasurement);
  }
}

uint8_t Module::getNMeasurements() 
{
  return nMeasurements;
}

Measurement *Module::getMeasurements()
{
  return measurements;
}

Measurement *Module::getMeasurementByName(const char *name)
{
  for (int i = 0; i < nMeasurements; i++) {
    Measurement *current = measurements + i;
    if (strcmp(current->getName(), name) == 0)
      return current;
  }

  return nullptr;
}
