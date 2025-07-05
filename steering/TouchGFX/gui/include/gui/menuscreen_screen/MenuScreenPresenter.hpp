#ifndef MENUSCREENPRESENTER_HPP
#define MENUSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

#include <vector>

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

    void setMenuTiles(std::vector<char*> menuTiles) override;
    void handleButtonDown() override;
    void handleButtonUp() override;
    void handleButtonConfirm() override;
    void handleButtonBack() override;
private:
    MenuScreenPresenter();

    MenuScreenView& view;
    std::vector<char*> menuTiles;

    int currentIndex;
    int firstTileIndex;
    int lastTileIndex;

    void adaptIndexes();
    void updateMenuTilesInView();
    void setSelected();
};

#endif // MENUSCREENPRESENTER_HPP
