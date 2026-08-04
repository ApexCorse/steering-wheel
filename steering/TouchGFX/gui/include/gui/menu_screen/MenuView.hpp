#ifndef MENUVIEW_HPP
#define MENUVIEW_HPP

#include <gui_generated/menu_screen/MenuViewBase.hpp>
#include <gui/menu_screen/MenuPresenter.hpp>

class MenuView : public MenuViewBase
{
public:
    MenuView();
    virtual ~MenuView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void setSections(section_meta_t *sections, uint16_t nSections);
    void setSelected(int index);
private:
    void reset();
    void hideUnusedTiles(int nUsedTiles);
};

#endif // MENUVIEW_HPP
