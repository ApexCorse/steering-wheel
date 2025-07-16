#include <Measurement.hpp>

Measurement::Measurement() {}

Measurement::Measurement(json_t const *json) : JsonBase(json), hasMinValue(false), hasMaxValue(false) 
{
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

  json_t const *type = getPropertyOfType("type", JSON_INTEGER);
  if (type) {
    this->type = (Type)json_getInteger(type);
  }
}

void Measurement::setValue(double newValue) {
  value = newValue;
}

double Measurement::getValue() 
{
  return value;
}

Type Measurement::getType()
{
  return type;
}
