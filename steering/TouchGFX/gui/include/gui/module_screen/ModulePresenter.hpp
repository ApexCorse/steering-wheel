#ifndef MODULEPRESENTER_HPP
#define MODULEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>
#include <gui/common/ListManager.hpp>

using namespace touchgfx;

class ModuleView;

class ModulePresenter : public touchgfx::Presenter, public ModelListener, public ListManager<sensor_meta_t>
{
public:
    ModulePresenter(ModuleView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~ModulePresenter() {}
    void setSensors(const sensor_meta_t *sensors, uint16_t nSensors) override;
    void setModuleTitle(char const *name) override;
    void handleButtonDown() override;
    void handleButtonUp() override;
    void handleButtonBack() override;
private:
    ModulePresenter();


    ModuleView& view;

    void updateItemTilesInView(sensor_meta_t *items, uint16_t nItems) override;
    void setSelected();
};

#endif // MODULEPRESENTER_HPP
