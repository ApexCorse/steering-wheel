#ifndef MODULE_H
#define MODULE_H

#include <JsonBase.hpp>
#include <Measurement.hpp>

class Module : public JsonBase {
public:
  Module();
  Module(json_t const *json);
  static const size_t MAX_MEASUREMENTS = 64;

  void getMeasurements(Measurement (&arr)[MAX_MEASUREMENTS]);
  size_t getNMeasurements();
private:
  Measurement measurements[MAX_MEASUREMENTS];
  size_t nMeasurements;
};

#endif
