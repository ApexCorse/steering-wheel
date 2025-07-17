#ifndef SECTIONSCREENVIEW_HPP
#define SECTIONSCREENVIEW_HPP

#include <gui_generated/sectionscreen_screen/SectionScreenViewBase.hpp>
#include <gui/sectionscreen_screen/SectionScreenPresenter.hpp>
#include <Configuration.hpp>

class SectionScreenView : public SectionScreenViewBase
{
public:
    SectionScreenView();
    virtual ~SectionScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void setModules(Module *modules[], uint8_t nModules);
    void setSelected(uint8_t index);
    void setTitle(char const *name);
private:
    void hideUnusedTiles(uint8_t nTilesUsed);
    void reset();
};

#endif // SECTIONSCREENVIEW_HPP
