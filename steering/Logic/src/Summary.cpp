#include <Summary.hpp>

Summary::Summary(json_t const *json): JsonBase(json) 
{
  json_t const *measurements = json_getProperty(json, "measurements");
  if (!measurements || json_getType(measurements) != JSON_ARRAY) return;

  json_t const *currentJsonMeasurement = json_getChild(measurements);
  if (!currentJsonMeasurement) return;

  firstMeasurement = new Measurement(currentJsonMeasurement);
  firstMeasurement->next = nullptr;
  Measurement *currentMeasurement = firstMeasurement;
  nMeasurements = 1;

  currentJsonMeasurement = json_getSibling(currentJsonMeasurement);

  while (currentJsonMeasurement) {
    Measurement *newMeasurement = new Measurement(currentJsonMeasurement);
    newMeasurement->next = nullptr;
    currentMeasurement->next = newMeasurement;
    currentMeasurement = newMeasurement;

    nMeasurements++;
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
  Measurement *current = firstMeasurement;
  uint8_t i = 0;
  double sum = 0;

  while (current && i < nMeasurements) {
    sum += current->getValue();

    i++;
    current = current->next;
  }

  return sum;
}

double Summary::calculateAvg()
{
  return calculateSum() / nMeasurements;
}

double Summary::calculateMin()
{
  Measurement *current = firstMeasurement;
  uint8_t i = 0;
  double min = current->getValue();

  while (current && i < nMeasurements) {
    if (current->getValue() < min) {
      min = current->getValue();
    }

    i++;
    current = current->next;
  }

  return min;
}

double Summary::calculateMax()
{
  Measurement *current = firstMeasurement;
  uint8_t i = 0;
  double max = current->getValue();

  while (current && i < nMeasurements) {
    if (current->getValue() > max) {
      max = current->getValue();
    }

    i++;
    current = current->next;
  }

  return max;
}
