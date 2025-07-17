#ifndef MODULETILE_HPP
#define MODULETILE_HPP

#include <gui_generated/containers/ModuleTileBase.hpp>

class ModuleTile : public ModuleTileBase
{
public:
    ModuleTile();
    virtual ~ModuleTile() {}

    virtual void initialize();

    void setText(char const *text);
    void setSelected(bool selected);
    void setVisible(bool visible);
protected:
};

#endif // MODULETILE_HPP