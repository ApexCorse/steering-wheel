#include <gui/sectionscreen_screen/SectionScreenView.hpp>
#include <gui/sectionscreen_screen/SectionScreenPresenter.hpp>

#include <algorithm>

SectionScreenPresenter::SectionScreenPresenter(SectionScreenView& v)
    : ListManager(5), view(v)
{

}

void SectionScreenPresenter::activate()
{
    model->initSectionMenu();
    model->initSectionTitle();
}

void SectionScreenPresenter::deactivate()
{

}

void SectionScreenPresenter::setModules(Module *modules[], uint8_t nModules)
{
    ListManager<Module>::setItems(modules, nModules);
}

void SectionScreenPresenter::setSectionTitle(char const *name)
{
    view.setTitle(name);
}

void SectionScreenPresenter::handleButtonDown()
{
    ListManager<Module>::handleButtonUp();
}

void SectionScreenPresenter::handleButtonUp()
{
    ListManager<Module>::handleButtonUp();
}

void SectionScreenPresenter::handleButtonConfirm()
{
    if (currentIndex < static_cast<uint8_t>(0) || currentIndex >= nItems) return;

    if (items[currentIndex] == nullptr) return;

    model->setChosenModule(items[currentIndex]->getName());
    view.gotoModuleScreen();
}

void SectionScreenPresenter::handleButtonBack()
{
    
}

void SectionScreenPresenter::updateItemTilesInView(Module *items[], uint8_t nItems)
{
    view.setModules(items, nItems);
}

void SectionScreenPresenter::setSelected()
{
    view.setSelected(currentIndex - firstTileIndex);
}
