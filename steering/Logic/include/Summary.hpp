#ifndef SUMMARY_HPP
#define SUMMARY_HPP

#include <JsonBase.hpp>
#include <Measurement.hpp>

typedef enum {
  SUMMARY_AVG = 0,
  SUMMARY_MIN,
  SUMMARY_MAX,
  SUMMARY_SUM
} SummaryType;

class Summary : public JsonBase {
public:
  Summary();
  Summary(json_t const *json);

  Summary *next;
  double calculate();
private:
  SummaryType type;

  // Linked list
  Measurement *firstMeasurement;
  uint8_t nMeasurements;

  double calculateAvg();
  double calculateMin();
  double calculateMax();
  double calculateSum();
};

#endif
