#include <gui/modulescreen_screen/ModuleScreenView.hpp>
#include <gui/modulescreen_screen/ModuleScreenPresenter.hpp>

#include <algorithm>

ModuleScreenPresenter::ModuleScreenPresenter(ModuleScreenView& v)
    : ListManager(10), view(v)
{

}

void ModuleScreenPresenter::activate()
{
    model->initModuleMenu();
    model->initModuleTitle();
}

void ModuleScreenPresenter::deactivate()
{

}

void ModuleScreenPresenter::setMeasurements(Measurement *measurements[], uint8_t nMeasurements)
{
    ListManager<Measurement>::setItems(measurements, nMeasurements);
}

void ModuleScreenPresenter::setModuleTitle(char const *name)
{
    view.setTitle(name);
}

void ModuleScreenPresenter::handleButtonDown()
{
    ListManager<Measurement>::handleButtonDown();
}

void ModuleScreenPresenter::handleButtonUp()
{
    ListManager<Measurement>::handleButtonUp();
}

void ModuleScreenPresenter::handleButtonBack()
{
    
}

void ModuleScreenPresenter::updateItemTilesInView(Measurement *items[], uint8_t nItems)
{
    view.setMeasurements(items, nItems);
}

void ModuleScreenPresenter::setSelected()
{
    view.setSelected(currentIndex - firstTileIndex);
}
