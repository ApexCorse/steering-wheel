#ifndef MEASUREMENT_HPP
#define MEASUREMENT_HPP

#include <JsonBase.hpp>

struct Value {
  enum Type { INT, DOUBLE } t;
  union {
    int i;
    double d;
  } v;
};

class Measurement : public JsonBase {
public:
  Measurement();
  Measurement(json_t const *json);

  Measurement *next;
  void setValue(double newValue);
  Value getValue();
private:
  Value value;

  bool hasMinValue;
  bool hasMaxValue;
  
  double minValue;
  double maxValue;
};

#endif
