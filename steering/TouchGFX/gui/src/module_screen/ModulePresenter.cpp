#include <gui/module_screen/ModuleView.hpp>
#include <gui/module_screen/ModulePresenter.hpp>

#include <algorithm>

ModulePresenter::ModulePresenter(ModuleView& v)
    : ListManager(10), view(v)
{

}

void ModulePresenter::activate()
{
    model->initModuleMenu();
    model->initModuleTitle();
}

void ModulePresenter::deactivate()
{

}

void ModulePresenter::setMeasurements(Measurement *measurements[], uint8_t nMeasurements)
{
    ListManager<Measurement>::setItems(measurements, nMeasurements);
}

void ModulePresenter::setModuleTitle(char const *name)
{
    view.setTitle(name);
}

void ModulePresenter::handleButtonDown()
{
    ListManager<Measurement>::handleButtonDown();
}

void ModulePresenter::handleButtonUp()
{
    ListManager<Measurement>::handleButtonUp();
}

void ModulePresenter::handleButtonBack()
{
    
}

void ModulePresenter::updateItemTilesInView(Measurement *items[], uint8_t nItems)
{
    view.setMeasurements(items, nItems);
}

void ModulePresenter::setSelected()
{
    view.setSelected(currentIndex - firstTileIndex);
}
