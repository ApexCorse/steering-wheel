#ifndef MEASUREMENT_HPP
#define MEASUREMENT_HPP

#include <JsonBase.hpp>

typedef enum Type { INT = 0, DOUBLE } Type;

class Measurement : public JsonBase {
public:
  Measurement();
  Measurement(json_t const *json);

  Measurement *next;
  void setValue(double newValue);
  double getValue();
  Type getType();
private:
  double value;
  Type type;

  bool hasMinValue;
  bool hasMaxValue;
  
  double minValue;
  double maxValue;
};

#endif
