#include <gui/menu_screen/MenuView.hpp>
#include <gui/menu_screen/MenuPresenter.hpp>

#include <algorithm>
#include <cstring>

MenuPresenter::MenuPresenter(MenuView& v)
    : ListManager(5), view(v)
{

}

void MenuPresenter::activate()
{
    model->initSections();
}

void MenuPresenter::deactivate()
{

}

void MenuPresenter::setSections(Section *sections[], uint8_t nSections)
{
    ListManager<Section>::setItems(sections, nSections);
}

void MenuPresenter::handleButtonDown()
{
    ListManager<Section>::handleButtonDown();
}

void MenuPresenter::handleButtonUp()
{
    ListManager<Section>::handleButtonUp();
}

void MenuPresenter::handleButtonConfirm()
{
    if (currentIndex < static_cast<uint8_t>(0) || currentIndex >= nItems) return;

    if (items[currentIndex] == nullptr) return;

    if (strcmp(items[currentIndex]->getName(), "Drive") == 0) {
        view.gotoDriveScreen();
    } else if (strcmp(items[currentIndex]->getName(), "Start Up") == 0) {
        view.gotoStartUpScreen();
    } else {
        model->setChosenSection(items[currentIndex]->getName());
        view.gotoSectionScreen();
    }
}

void MenuPresenter::handleButtonBack()
{
    
}

void MenuPresenter::updateItemTilesInView(Section *items[], uint8_t nItems)
{
    view.setSections(items, nItems);
}

void MenuPresenter::setSelected()
{
    view.setSelected(currentIndex - firstTileIndex);
}
