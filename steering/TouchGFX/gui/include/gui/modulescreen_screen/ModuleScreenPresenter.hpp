#ifndef MODULESCREENPRESENTER_HPP
#define MODULESCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ModuleScreenView;

class ModuleScreenPresenter : public touchgfx::Presenter, public ModelListener
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
    static const uint8_t MAX_MEASUREMENTS = 16;
    void setMeasurements(Measurement *measurements[], uint8_t nMeasurements);
    void setModuleTitle(char const *name) override;
    void handleButtonDown() override;
    void handleButtonUp() override;
    void handleButtonBack() override;
private:
    ModuleScreenPresenter();

    ModuleScreenView& view;

    void adaptIndexes();
    void updateMeasurementTilesInView();
    void setSelected();

    uint8_t currentIndex;
    uint8_t firstTileIndex;
    uint8_t lastTileIndex;

    const uint8_t NUM_TILES_TO_SHOW = 4;
    uint8_t nMeasurements;
    Measurement *measurements[MAX_MEASUREMENTS];
};

#endif // MODULESCREENPRESENTER_HPP
