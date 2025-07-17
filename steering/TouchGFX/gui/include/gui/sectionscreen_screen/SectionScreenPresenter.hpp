#ifndef SECTIONSCREENPRESENTER_HPP
#define SECTIONSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SectionScreenView;

class SectionScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    SectionScreenPresenter(SectionScreenView& v);

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

    virtual ~SectionScreenPresenter() {}

    static const uint8_t MAX_MODULES = 16;
    void setModules(Module *modules[], uint8_t nModules) override;
    void setSectionTitle(char const *name) override;
    void handleButtonDown() override;
    void handleButtonUp() override;
    void handleButtonConfirm() override;
    void handleButtonBack() override;
private:
    SectionScreenPresenter();

    SectionScreenView& view;

    void adaptIndexes();
    void updateModuleTilesInView();
    void setSelected();

    uint8_t currentIndex;
    uint8_t firstTileIndex;
    uint8_t lastTileIndex;

    const uint8_t NUM_TILES_TO_SHOW = 5;
    uint8_t nModules;
    Module *modules[MAX_MODULES];
};

#endif // SECTIONSCREENPRESENTER_HPP
