#ifndef MEASUREMENT_HPP
#define MEASUREMENT_HPP

#include <JsonBase.hpp>

typedef enum MeasurementType { INT = 0, DOUBLE } MeasurementType;

class Measurement : public JsonBase {
public:
  Measurement();
  Measurement(json_t const *json);

  Measurement *next;
  void setValue(double newValue);
  double getValue();
  MeasurementType getType();
private:
  double value;
  MeasurementType type;

  bool hasMinValue;
  bool hasMaxValue;
  
  double minValue;
  double maxValue;
};

#endif
