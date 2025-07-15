#ifndef MODEL_HPP
#define MODEL_HPP

#include <Configuration.hpp>

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
    void initMenuItems();
protected:
    ModelListener* modelListener;
    int speed;
    int maxTemp;
    int avgTemp;
    int batteryLevel;
    int batteryPower;

    Configuration *configuration;
    char chosenSection[256];
    char chosenModule[256];
};

#endif // MODEL_HPP
