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
    void initSections();
    void initSectionMenu();
    void initSectionTitle();
    void initModuleMenu();
    void initModuleTitle();

    void setChosenSection(char const *name);
    void setChosenModule(char const *name);

    char currentScreen[16];
    char previousScreen[16];
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
