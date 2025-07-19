#include <gui/menuscreen_screen/MenuScreenView.hpp>
#include <gui/menuscreen_screen/MenuScreenPresenter.hpp>

#include <algorithm>
#include <cstring>

MenuScreenPresenter::MenuScreenPresenter(MenuScreenView& v)
    : ListManager(5), view(v)
{

}

void MenuScreenPresenter::activate()
{
    model->initSections();
}

void MenuScreenPresenter::deactivate()
{

}

void MenuScreenPresenter::setSections(Section *sections[], uint8_t nSections)
{
    ListManager<Section>::setItems(sections, nSections);
}

void MenuScreenPresenter::handleButtonDown()
{
    ListManager<Section>::handleButtonDown();
}

void MenuScreenPresenter::handleButtonUp()
{
    ListManager<Section>::handleButtonUp();
}

void MenuScreenPresenter::handleButtonConfirm()
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

void MenuScreenPresenter::handleButtonBack()
{
    
}

void MenuScreenPresenter::updateItemTilesInView(Section *items[], uint8_t nItems)
{
    view.setSections(items, nItems);
}

void MenuScreenPresenter::setSelected()
{
    view.setSelected(currentIndex - firstTileIndex);
}
