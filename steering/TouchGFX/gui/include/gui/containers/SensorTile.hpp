#ifndef SENSORTILE_HPP
#define SENSORTILE_HPP

#include <gui_generated/containers/SensorTileBase.hpp>

class SensorTile : public SensorTileBase
{
public:
    SensorTile();
    virtual ~SensorTile() {}

    virtual void initialize();

    void setVisible(bool visible);
    void setSelected(bool selected);
    void setLabel(char const *text);
    void setValue(float value);
protected:
};

#endif // SENSORTILE_HPP
