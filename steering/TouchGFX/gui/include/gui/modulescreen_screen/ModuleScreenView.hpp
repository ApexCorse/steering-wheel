#ifndef MODULESCREENVIEW_HPP
#define MODULESCREENVIEW_HPP

#include <gui_generated/modulescreen_screen/ModuleScreenViewBase.hpp>
#include <gui/modulescreen_screen/ModuleScreenPresenter.hpp>

class ModuleScreenView : public ModuleScreenViewBase
{
public:
    ModuleScreenView();
    virtual ~ModuleScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void setMeasurements(Measurement *measurements[], uint8_t nMeasurements);
    void setSelected(uint8_t index);
    void setTitle(char const *name);
private:
    void hideUnusedTiles(uint8_t nTilesUsed);
    void reset();
};

#endif // MODULESCREENVIEW_HPP
