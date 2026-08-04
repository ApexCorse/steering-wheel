#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
#include <sensor_storage.h>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    virtual void setSpeed(int speed) {}
    virtual void setMaxTemp(int maxTemp) {}
    virtual void setAvgTemp(int avgTemp) {}
    virtual void setBatteryLevel(int batteryLevel, int minBatteryLevel, int maxBatteryLevel) {}
    virtual void setBatteryPower(int batteryPower, int minBatteryPower, int maxBatteryPower) {}

    virtual void setSections(const section_meta_t *sections, uint16_t nSections) {}
    virtual void setModules(const module_meta_t *modules, uint16_t nModules) {}
    virtual void setSensors(const sensor_meta_t *sensors, uint16_t nSensors) {}
    virtual void setSectionTitle(char const *name) {}
    virtual void setModuleTitle(char const *name) {}

    virtual void handleButtonDown() {}
    virtual void handleButtonUp() {}
    virtual void handleButtonConfirm() {}
    virtual void handleButtonBack() {}
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
