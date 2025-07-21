#include <gui/section_screen/SectionView.hpp>
#include <gui/section_screen/SectionPresenter.hpp>

#include <algorithm>

SectionPresenter::SectionPresenter(SectionView& v)
    : ListManager(5), view(v)
{

}

void SectionPresenter::activate()
{
    model->initSectionMenu();
    model->initSectionTitle();
}

void SectionPresenter::deactivate()
{

}

void SectionPresenter::setModules(Module *modules[], uint8_t nModules)
{
    ListManager<Module>::setItems(modules, nModules);
}

void SectionPresenter::setSectionTitle(char const *name)
{
    view.setTitle(name);
}

void SectionPresenter::handleButtonDown()
{
    ListManager<Module>::handleButtonUp();
}

void SectionPresenter::handleButtonUp()
{
    ListManager<Module>::handleButtonUp();
}

void SectionPresenter::handleButtonConfirm()
{
    if (currentIndex < static_cast<uint8_t>(0) || currentIndex >= nItems) return;

    if (items[currentIndex] == nullptr) return;

    model->setChosenModule(items[currentIndex]->getName());
    view.gotoModuleScreen();
}

void SectionPresenter::handleButtonBack()
{
    
}

void SectionPresenter::updateItemTilesInView(Module *items[], uint8_t nItems)
{
    view.setModules(items, nItems);
}

void SectionPresenter::setSelected()
{
    view.setSelected(currentIndex - firstTileIndex);
}

