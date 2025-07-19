#ifndef MODULESCREENPRESENTER_HPP
#define MODULESCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>
#include <gui/common/ListManager.hpp>

using namespace touchgfx;

class ModuleScreenView;

class ModuleScreenPresenter : public touchgfx::Presenter, public ModelListener, public ListManager<Measurement>
{
public:
    ModuleScreenPresenter(ModuleScreenView& v);

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

    virtual ~ModuleScreenPresenter() {}
    void setMeasurements(Measurement *measurements[], uint8_t nMeasurements) override;
    void setModuleTitle(char const *name) override;
    void handleButtonDown() override;
    void handleButtonUp() override;
    void handleButtonBack() override;
private:
    ModuleScreenPresenter();

    int scrollAmount() override { return 2; }

    ModuleScreenView& view;

    void updateItemTilesInView(Measurement *items[], uint8_t nItems) override;
    void setSelected();
};

#endif // MODULESCREENPRESENTER_HPP
