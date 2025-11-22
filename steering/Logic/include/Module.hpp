#ifndef MODULE_HPP
#define MODULE_HPP

#include <JsonBase.hpp>
#include <Measurement.hpp>


class Module : public JsonBase {
public:
  Module();
  Module(json_t const *json);

  uint8_t getNMeasurements();
  Measurement *getMeasurements();
  Measurement *getMeasurementByName(const char *name);
private:
  // Linked list
  Measurement measurements[CONFIGURATION_MAX_MEASUREMENTS];
  uint8_t nMeasurements;
};

#endif
