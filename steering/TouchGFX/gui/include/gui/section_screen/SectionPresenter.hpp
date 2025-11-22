#ifndef SECTIONPRESENTER_HPP
#define SECTIONPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>
#include <gui/common/ListManager.hpp>

using namespace touchgfx;

class SectionView;

class SectionPresenter : public touchgfx::Presenter, public ModelListener, public ListManager<Module>
{
public:
    SectionPresenter(SectionView& v);

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

    virtual ~SectionPresenter() {}

    void setModules(Module *modules, uint8_t nModules) override;
    void setSectionTitle(char const *name) override;
    void handleButtonDown() override;
    void handleButtonUp() override;
    void handleButtonConfirm() override;
    void handleButtonBack() override;
private:
    SectionPresenter();

    SectionView& view;

    void updateItemTilesInView(Module *items, uint8_t nItems) override;
    void setSelected() override;
};

#endif // SECTIONPRESENTER_HPP
