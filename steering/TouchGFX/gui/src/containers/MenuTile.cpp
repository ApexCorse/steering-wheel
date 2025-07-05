#include <gui/containers/MenuTile.hpp>
#include <touchgfx/Color.hpp>

MenuTile::MenuTile()
{

}

void MenuTile::initialize()
{
    MenuTileBase::initialize();
}

void MenuTile::setText(const char *text) 
{
    Unicode::strncpy(tileNameBuffer, text, TILENAME_SIZE);
    tileName.invalidate();
}

void MenuTile::setDividerVisible(bool visible)
{
    divider.setVisible(visible);
}

void MenuTile::setSelected(bool selected)
{
    if (selected) {
        background.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
        return;
    }

    background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
}