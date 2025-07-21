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
    strcpy(model->currentScreen, "Menu");
}

void MenuPresenter::deactivate()
{
    strcpy(model->previousScreen, "Menu");
}

void MenuPresenter::setSections(Section *sections[], uint8_t nSections)
{
    ListManager<Section>::setItems(sections, nSections);
}

void MenuPresenter::handleButtonDown()
{
    if (strcmp(model->currentScreen, "Menu") != 0) return;

    ListManager<Section>::handleButtonDown();
}

void MenuPresenter::handleButtonUp()
{
    if (strcmp(model->currentScreen, "Menu") != 0) return;

    ListManager<Section>::handleButtonUp();
}

void MenuPresenter::handleButtonConfirm()
{
    if (strcmp(model->currentScreen, "Menu") != 0) return;

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
    if (strcmp(model->currentScreen, "Menu") != 0) return;

    if (strcmp(model->previousScreen, "Drive") == 0) {
        view.gotoDriveScreen();
    } else if (strcmp(model->previousScreen, "Section") == 0) {
        view.gotoSectionScreen();
    }
}

void MenuPresenter::updateItemTilesInView(Section *items[], uint8_t nItems)
{
    view.setSections(items, nItems);
}

void MenuPresenter::setSelected()
{
    view.setSelected(currentIndex - firstTileIndex);
}
