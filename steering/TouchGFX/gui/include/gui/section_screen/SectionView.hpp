#ifndef SECTIONVIEW_HPP
#define SECTIONVIEW_HPP

#include <gui_generated/section_screen/SectionViewBase.hpp>
#include <gui/section_screen/SectionPresenter.hpp>
#include <Configuration.hpp>

class SectionView : public SectionViewBase
{
public:
    SectionView();
    virtual ~SectionView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void setModules(Module *modules, uint8_t nModules);
    void setSelected(uint8_t index);
    void setTitle(char const *name);
private:
    void hideUnusedTiles(uint8_t nTilesUsed);
    void reset();
};

#endif // SECTIONVIEW_HPP
