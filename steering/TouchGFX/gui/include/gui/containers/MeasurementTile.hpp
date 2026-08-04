#ifndef MEASUREMENTTILE_HPP
#define MEASUREMENTTILE_HPP

#include <gui_generated/containers/MeasurementTileBase.hpp>

enum MeasurementType {
	INT,
	FLOAT
};

class MeasurementTile : public MeasurementTileBase
{
public:
    MeasurementTile();
    virtual ~MeasurementTile() {}

    virtual void initialize();

    void setVisible(bool visible);
    void setSelected(bool selected);
    void setLabel(char const *text);
    void setValue(double value, MeasurementType type);
protected:
};

#endif // MEASUREMENTTILE_HPP
