#include <gui/containers/SectionTile.hpp>
#include <touchgfx/Color.hpp>

SectionTile::SectionTile()
{

}

void SectionTile::initialize()
{
    SectionTileBase::initialize();
}

void SectionTile::setText(const char *text) 
{
    Unicode::strncpy(sectionNameBuffer, text, SECTIONNAME_SIZE);
    sectionName.invalidate();
}

void SectionTile::setSelected(bool selected)
{
    if (selected) {
        background.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
        return;
    }

    background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
}
