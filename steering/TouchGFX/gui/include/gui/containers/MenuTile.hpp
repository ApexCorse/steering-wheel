#ifndef MENUTILE_HPP
#define MENUTILE_HPP

#include <gui_generated/containers/MenuTileBase.hpp>

class MenuTile : public MenuTileBase
{
public:
    MenuTile();
    virtual ~MenuTile() {}

    virtual void initialize();

    void setText(const char *text);
    void setDividerVisible(bool visible);
    void setSelected(bool selected);
protected:
};

#endif // MENUTILE_HPP
