#include <gui/containers/GeneralMeasurement.hpp>

GeneralMeasurement::GeneralMeasurement()
{

}

void GeneralMeasurement::initialize()
{
    GeneralMeasurementBase::initialize();
}

void GeneralMeasurement::setLabel(char *text)
{
    Unicode::strncpy(labelBuffer, text, LABEL_SIZE);
    label.invalidate();
}

void GeneralMeasurement::setValue(char *text)
{
    Unicode::strncpy(valueBuffer, text, VALUE_SIZE);
    value.invalidate();
}

void GeneralMeasurement::setVisible(bool visible)
{
    value.setVisible(visible);
    label.setVisible(visible);
}