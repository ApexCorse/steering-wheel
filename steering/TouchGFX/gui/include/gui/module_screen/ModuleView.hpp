#ifndef MODULEVIEW_HPP
#define MODULEVIEW_HPP

#include <gui_generated/module_screen/ModuleViewBase.hpp>
#include <gui/module_screen/ModulePresenter.hpp>

class ModuleView : public ModuleViewBase
{
public:
    ModuleView();
    virtual ~ModuleView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void setMeasurements(Measurement *measurements, uint8_t nMeasurements);
    void setSelected(uint8_t index);
    void setTitle(char const *name);
private:
    void hideUnusedTiles(uint8_t nTilesUsed);
    void reset();
};

#endif // MODULEVIEW_HPP
