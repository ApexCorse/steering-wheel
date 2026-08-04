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

void ModulePresenter::setSensors(const sensor_meta_t *sensors, uint16_t nSensors)
{
		ListManager<sensor_meta_t>::setItems(sensors, nSensors);
}

void ModulePresenter::setModuleTitle(char const *name)
{
    view.setTitle(name);
}

void ModulePresenter::handleButtonDown()
{
    if (strcmp(model->currentScreen, "Module") != 0) return;

    ListManager<sensor_meta_t>::handleButtonDown();
}

void ModulePresenter::handleButtonUp()
{
    if (strcmp(model->currentScreen, "Module") != 0) return;

    ListManager<sensor_meta_t>::handleButtonUp();
}

void ModulePresenter::handleButtonBack()
{
    if (strcmp(model->currentScreen, "Module") != 0) return;

    view.gotoSectionScreen();
}

void ModulePresenter::updateItemTilesInView(sensor_meta_t *items, uint16_t nItems)
{
    view.setSensors(items, nItems);
}

void ModulePresenter::setSelected()
{
    view.setSelected(currentIndex - firstTileIndex);
}
