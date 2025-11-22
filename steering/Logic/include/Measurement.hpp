#ifndef MEASUREMENT_HPP
#define MEASUREMENT_HPP

#include <JsonBase.hpp>

#define CONFIGURATION_MAX_MEASUREMENTS 1

typedef enum MeasurementType { INT = 0, DOUBLE } MeasurementType;

class Measurement : public JsonBase {
public:
  Measurement();
  Measurement(json_t const *json);

  void setValue(float newValue);
  float getValue();
  MeasurementType getType();
private:
  float value;
  MeasurementType type;
};

#endif
