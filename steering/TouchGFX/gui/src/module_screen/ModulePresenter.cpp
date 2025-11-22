#include <gui/module_screen/ModuleView.hpp>
#include <gui/module_screen/ModulePresenter.hpp>

#include <algorithm>
#include <cstring>

ModulePresenter::ModulePresenter(ModuleView& v)
    : ListManager(10), view(v)
{

}

void ModulePresenter::activate()
{
    model->initModuleMenu();
    model->initModuleTitle();

    strcpy(model->currentScreen, "Module");
}

void ModulePresenter::deactivate()
{
    strcpy(model->previousScreen, "Module");
}

void ModulePresenter::setMeasurements(Measurement *measurements, uint8_t nMeasurements)
{
    ListManager<Measurement>::setItems(measurements, nMeasurements);
}

void ModulePresenter::setModuleTitle(char const *name)
{
    view.setTitle(name);
}

void ModulePresenter::handleButtonDown()
{
    if (strcmp(model->currentScreen, "Module") != 0) return;

    ListManager<Measurement>::handleButtonDown();
}

void ModulePresenter::handleButtonUp()
{
    if (strcmp(model->currentScreen, "Module") != 0) return;

    ListManager<Measurement>::handleButtonUp();
}

void ModulePresenter::handleButtonBack()
{
    if (strcmp(model->currentScreen, "Module") != 0) return;

    view.gotoSectionScreen();
}

void ModulePresenter::updateItemTilesInView(Measurement *items, uint8_t nItems)
{
    view.setMeasurements(items, nItems);
}

void ModulePresenter::setSelected()
{
    view.setSelected(currentIndex - firstTileIndex);
}
