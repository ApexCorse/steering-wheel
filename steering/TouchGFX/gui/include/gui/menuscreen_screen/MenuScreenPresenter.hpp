#ifndef MENUSCREENPRESENTER_HPP
#define MENUSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MenuScreenView;

class MenuScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    MenuScreenPresenter(MenuScreenView& v);

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

    virtual ~MenuScreenPresenter() {}

    void setSections(Section *sections[], uint8_t nSection) override;
    void handleButtonDown() override;
    void handleButtonUp() override;
    void handleButtonConfirm() override;
    void handleButtonBack() override;

    static const uint8_t MAX_SECTIONS = 16;
private:
    MenuScreenPresenter();
    
    MenuScreenView& view;

    void adaptIndexes();
    void updateSectionTilesInView();
    void setSelected();

    int currentIndex;
    int firstTileIndex;
    int lastTileIndex;

    const uint8_t NUM_TILES_TO_SHOW = 5;
    uint8_t nSections;
    Section *sections[MAX_SECTIONS];
};

#endif // MENUSCREENPRESENTER_HPP
