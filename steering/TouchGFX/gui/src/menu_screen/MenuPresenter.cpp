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

void MenuPresenter::setSections(const section_meta_t *sections, uint16_t nSections)
{
    ListManager<section_meta_t>::setItems(sections, nSections);
}

void MenuPresenter::handleButtonDown()
{
    if (strcmp(model->currentScreen, "Menu") != 0) return;

    ListManager<section_meta_t>::handleButtonDown();
}

void MenuPresenter::handleButtonUp()
{
    if (strcmp(model->currentScreen, "Menu") != 0) return;

    ListManager<section_meta_t>::handleButtonUp();
}

void MenuPresenter::handleButtonConfirm()
{
    if (strcmp(model->currentScreen, "Menu") != 0) return;

    if (currentIndex < static_cast<uint16_t>(0) || currentIndex >= nItems) return;

    if (strcmp(items[currentIndex].name, "Drive") == 0) {
        view.gotoDriveScreen();
    } else if (strcmp(items[currentIndex].name, "Start Up") == 0) {
        view.gotoStartUpScreen();
    } else {
        model->setChosenSection(items[currentIndex].name);
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

void MenuPresenter::updateItemTilesInView(section_meta_t *items, uint16_t nItems)
{
    view.setSections(items, nItems);
}

void MenuPresenter::setSelected()
{
    view.setSelected(currentIndex - firstTileIndex);
}
