#ifndef SECTIONVIEW_HPP
#define SECTIONVIEW_HPP

#include <gui_generated/section_screen/SectionViewBase.hpp>
#include <gui/section_screen/SectionPresenter.hpp>

class SectionView : public SectionViewBase
{
public:
    SectionView();
    virtual ~SectionView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void setModules(module_meta_t *modules, uint16_t nModules);
    void setSelected(uint16_t index);
    void setTitle(char const *name);
private:
    void hideUnusedTiles(uint16_t nTilesUsed);
    void reset();
};

#endif // SECTIONVIEW_HPP
