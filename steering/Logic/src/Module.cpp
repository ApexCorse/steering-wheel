#include <Module.hpp>

Module::Module(json_t const *json): JsonBase(json) {
  json_t const *measurements = getPropertyOfType("measurements", JSON_ARRAY);
  if (!measurements) return;

  json_t const *current = measurements;
  while (current && nMeasurements < MAX_MEASUREMENTS) {
    Measurement newMeasurement(current);
    (this->measurements)[nMeasurements] = newMeasurement;

    nMeasurements++;
    current = json_getSibling(current);
  }
}

void Module::getMeasurements(Measurement (&arr)[MAX_MEASUREMENTS]) {
  for (size_t i = 0; i < nMeasurements; i++) {
    arr[i] = measurements[i];
  }
}

size_t Module::getNMeasurements() {
  return nMeasurements;
}
