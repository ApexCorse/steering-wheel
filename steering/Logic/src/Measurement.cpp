#include <Measurement.hpp>

Measurement::Measurement(json_t const *json) : JsonBase(json), hasMinValue(false), hasMaxValue(false) {
  json_t const *minValue = getPropertyOfType("minValue", JSON_BOOLEAN);
  if (minValue) {
    hasMinValue = true;
    this->minValue = json_getReal(minValue);
  } 

  json_t const *maxValue = getPropertyOfType("maxValue", JSON_BOOLEAN);
  if (maxValue) {
    hasMaxValue = true;
    this->maxValue = json_getReal(maxValue);
  }
}