#include <gui/containers/SensorTile.hpp>
#include <touchgfx/Color.hpp>

SensorTile::SensorTile()
{

}

void SensorTile::initialize()
{
    SensorTileBase::initialize();
}

void SensorTile::setLabel(char const *text)
{
    Unicode::strncpy(labelBuffer, text, LABEL_SIZE);
    label.invalidate();
}

void SensorTile::setValue(float value)
{
    Unicode::snprintfFloat(valueBuffer, VALUE_SIZE, "%.1f", value);
    (this->value).invalidate();
}

void SensorTile::setSelected(bool selected)
{
    if (selected) {
        background.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
        label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        return;
    }

    background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    label.setColor(touchgfx::Color::getColorFromRGB(168, 168, 168));
}

void SensorTile::setVisible(bool visible) 
{
    background.setVisible(visible);
    label.setVisible(visible);
    value.setVisible(visible);
}
