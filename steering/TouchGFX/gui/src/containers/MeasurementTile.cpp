#include <gui/containers/MeasurementTile.hpp>
#include <touchgfx/Color.hpp>

MeasurementTile::MeasurementTile()
{

}

void MeasurementTile::initialize()
{
    MeasurementTileBase::initialize();
}

void MeasurementTile::setLabel(char const *text)
{
    Unicode::strncpy(labelBuffer, text, LABEL_SIZE);
    label.invalidate();
}

void MeasurementTile::setValue(double value, MeasurementType type)
{
    if (type == INT) {
        Unicode::snprintf(valueBuffer, VALUE_SIZE, "%d", value);
    } else {
        Unicode::snprintfFloat(valueBuffer, VALUE_SIZE, "%.1f", value);
    }
    (this->value).invalidate();
}

void MeasurementTile::setSelected(bool selected)
{
    if (selected) {
        background.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
        label.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        return;
    }

    background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    label.setColor(touchgfx::Color::getColorFromRGB(168, 168, 168));
}

void MeasurementTile::setVisible(bool visible) 
{
    background.setVisible(visible);
    label.setVisible(visible);
    value.setVisible(visible);
}
