#include <gui/section_screen/SectionView.hpp>
#include <gui/section_screen/SectionPresenter.hpp>

#include <algorithm>
#include <cstring>

SectionPresenter::SectionPresenter(SectionView& v)
    : ListManager(5), view(v)
{

}

void SectionPresenter::activate()
{
    model->initSectionMenu();
    model->initSectionTitle();

    strcpy(model->currentScreen, "Section");
}

void SectionPresenter::deactivate()
{
    strcpy(model->previousScreen, "Section");
}

void SectionPresenter::setModules(Module *modules, uint8_t nModules)
{
    ListManager<Module>::setItems(modules, nModules);
}

void SectionPresenter::setSectionTitle(char const *name)
{
    view.setTitle(name);
}

void SectionPresenter::handleButtonDown()
{
    if (strcmp(model->currentScreen, "Section") != 0) return;

    ListManager<Module>::handleButtonUp();
}

void SectionPresenter::handleButtonUp()
{
    if (strcmp(model->currentScreen, "Section") != 0) return;

    ListManager<Module>::handleButtonUp();
}

void SectionPresenter::handleButtonConfirm()
{
    if (strcmp(model->currentScreen, "Section") != 0) return;

    if (currentIndex < static_cast<uint8_t>(0) || currentIndex >= nItems) return;

    model->setChosenModule(items[currentIndex].getName());
    view.gotoModuleScreen();
}

void SectionPresenter::handleButtonBack()
{
    if (strcmp(model->currentScreen, "Section") != 0) return;
    
    view.gotoMenuScreen();
}

void SectionPresenter::updateItemTilesInView(Module *items, uint8_t nItems)
{
    view.setModules(items, nItems);
}

void SectionPresenter::setSelected()
{
    view.setSelected(currentIndex - firstTileIndex);
}

