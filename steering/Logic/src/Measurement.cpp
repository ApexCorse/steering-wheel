#include <Measurement.hpp>

Measurement::Measurement() {}

Measurement::Measurement(json_t const *json) : JsonBase(json), value(0) 
{
  json_t const *type = getPropertyOfType("type", JSON_INTEGER);
  if (type) {
    this->type = (MeasurementType)json_getInteger(type);
  }
}

void Measurement::setValue(float newValue) {
  value = newValue;
}

float Measurement::getValue() 
{
  return value;
}

MeasurementType Measurement::getType()
{
  return type;
}
