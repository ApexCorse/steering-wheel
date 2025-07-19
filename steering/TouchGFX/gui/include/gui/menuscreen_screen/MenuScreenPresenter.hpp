#ifndef MENUSCREENPRESENTER_HPP
#define MENUSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>
#include <gui/common/ListManager.hpp>

using namespace touchgfx;

class MenuScreenView;

class MenuScreenPresenter : public touchgfx::Presenter, public ModelListener, public ListManager<Section>
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
private:
    MenuScreenPresenter();
    
    MenuScreenView& view;

    void updateItemTilesInView(Section *items[], uint8_t nItems) override;
    void setSelected() override;
};

#endif // MENUSCREENPRESENTER_HPP
