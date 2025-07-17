#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

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

    virtual void setMenuItems(char* menuItems[], int nMenuItems) {}
    virtual void setModules(Module *modules[], uint8_t nModules) {}
    virtual void setSectionTitle(char const *name) {}

    virtual void handleButtonDown() {}
    virtual void handleButtonUp() {}
    virtual void handleButtonConfirm() {}
    virtual void handleButtonBack() {}
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
