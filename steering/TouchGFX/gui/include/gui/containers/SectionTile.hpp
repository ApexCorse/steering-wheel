#ifndef SECTIONTILE_HPP
#define SECTIONTILE_HPP

#include <gui_generated/containers/SectionTileBase.hpp>

class SectionTile : public SectionTileBase
{
public:
    SectionTile();
    virtual ~SectionTile() {}

    virtual void initialize();

    void setText(const char *text);
    void setSelected(bool selected);
protected:
};

#endif // SECTIONTILE_HPP
