#ifndef MODULE_HPP
#define MODULE_HPP

#include <JsonBase.hpp>
#include <Measurement.hpp>

class Module : public JsonBase {
public:
  Module();
  Module(json_t const *json);

  Module *next;

  uint8_t getNMeasurements();
  Measurement *getFirstMeasurement();
  Measurement *getMeasurementByName(const char *name);
private:
  // Linked list
  Measurement *firstMeasurement;
  uint8_t nMeasurements;
};

#endif
