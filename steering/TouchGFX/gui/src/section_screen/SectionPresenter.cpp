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

void SectionPresenter::setModules(const module_meta_t *modules, uint16_t nModules)
{
    ListManager<module_meta_t>::setItems(modules, nModules);
}

void SectionPresenter::setSectionTitle(char const *name)
{
    view.setTitle(name);
}

void SectionPresenter::handleButtonDown()
{
    if (strcmp(model->currentScreen, "Section") != 0) return;

    ListManager<module_meta_t>::handleButtonUp();
}

void SectionPresenter::handleButtonUp()
{
    if (strcmp(model->currentScreen, "Section") != 0) return;

    ListManager<module_meta_t>::handleButtonUp();
}

void SectionPresenter::handleButtonConfirm()
{
    if (strcmp(model->currentScreen, "Section") != 0) return;

    if (currentIndex < static_cast<uint8_t>(0) || currentIndex >= nItems) return;

    model->setChosenModule(items[currentIndex].name);
    view.gotoModuleScreen();
}

void SectionPresenter::handleButtonBack()
{
    if (strcmp(model->currentScreen, "Section") != 0) return;
    
    view.gotoMenuScreen();
}

void SectionPresenter::updateItemTilesInView(module_meta_t *items, uint16_t nItems)
{
    view.setModules(items, nItems);
}

void SectionPresenter::setSelected()
{
    view.setSelected(currentIndex - firstTileIndex);
}

