#include <Summary.hpp>

Summary::Summary(json_t const *json): JsonBase(json) 
{
  json_t const *measurements = json_getProperty(json, "measurements");
  if (!measurements || json_getType(measurements) != JSON_ARRAY) return;

  json_t const *currentJsonMeasurement = json_getChild(measurements);
  while (currentJsonMeasurement) {
    this->measurements[nMeasurements++] = Measurement(currentJsonMeasurement);

    currentJsonMeasurement = json_getSibling(currentJsonMeasurement);
  }
}

double Summary::calculate()
{
  switch (type) {
    case SUMMARY_AVG:
      return calculateAvg();
    case SUMMARY_MIN:
      return calculateMin();
    case SUMMARY_MAX: 
      return calculateMax(); 
    case SUMMARY_SUM:
      return calculateSum();
  }

  return 0;
}

double Summary::calculateSum()
{
  double sum = 0;
  for (int i = 0; i < nMeasurements; i++) {
    Measurement *current = measurements + i;
    sum += current->getValue();
  }

  return sum;
}

double Summary::calculateAvg()
{
  return calculateSum() / nMeasurements;
}

double Summary::calculateMin()
{
  double min = nMeasurements > 0 ? measurements[nMeasurements].getValue() : 0;

  for (int i = 1; i < nMeasurements; i++) {
    Measurement *current = measurements + i;
    if (current->getValue() < min) {
      min = current->getValue();
    }
  }

  return min;
}

double Summary::calculateMax()
{
  double max = nMeasurements > 0 ? measurements[nMeasurements].getValue() : 0;

  for (int i = 1; i < nMeasurements; i++) {
    Measurement *current = measurements + i;
    if (current->getValue() > max) {
      max = current->getValue();
    }
  }

  return max;
}
