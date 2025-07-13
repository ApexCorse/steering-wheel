#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <JsonBase.hpp>

class Measurement : public JsonBase {
public:
  Measurement();
  Measurement(json_t const *json);

private:
  bool hasMinValue;
  bool hasMaxValue;
  
  int minValue;
  int maxValue;
};

#endif
