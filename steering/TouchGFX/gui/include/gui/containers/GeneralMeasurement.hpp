#ifndef GENERALMEASUREMENT_HPP
#define GENERALMEASUREMENT_HPP

#include <gui_generated/containers/GeneralMeasurementBase.hpp>

class GeneralMeasurement : public GeneralMeasurementBase
{
public:
    GeneralMeasurement();
    virtual ~GeneralMeasurement() {}

    virtual void initialize();

    void setLabel(char *text);
    void setValue(char *text);
    void setVisible(bool visible);
protected:
};

#endif // GENERALMEASUREMENT_HPP
