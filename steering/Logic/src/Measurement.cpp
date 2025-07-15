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
  if (type && json_getInteger(type) == Value::INT) {
    (this->value).t = Value::INT;
    (this->value).v.i = 0;
  } else {
    (this->value).t = Value::DOUBLE;
    (this->value).v.d = 0;
  }
}

void Measurement::setValue(double newValue) {
  if (value.t == Value::INT) {
    value.v.i = static_cast<int>(newValue);
    return;
  }

  value.v.d = newValue;
}

Value Measurement::getValue() 
{
  return value;
}
