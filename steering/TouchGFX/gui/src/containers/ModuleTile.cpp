#include <gui/containers/ModuleTile.hpp>
#include <touchgfx/Color.hpp>

ModuleTile::ModuleTile()
{

}

void ModuleTile::initialize()
{
    ModuleTileBase::initialize();
}

void ModuleTile::setText(char const *text)
{
    Unicode::strncpy(moduleNameBuffer, text, MODULENAME_SIZE);
    moduleName.invalidate();
}

void ModuleTile::setSelected(bool selected)
{
    if (selected) {
        background.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
        return;
    }

    background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
}

void ModuleTile::setVisible(bool visible) 
{
    background.setVisible(visible);
    moduleName.setVisible(visible);
}