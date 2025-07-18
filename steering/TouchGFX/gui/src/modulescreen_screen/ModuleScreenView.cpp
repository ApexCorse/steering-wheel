#include <gui/modulescreen_screen/ModuleScreenView.hpp>

ModuleScreenView::ModuleScreenView()
{

}

void ModuleScreenView::setupScreen()
{
    ModuleScreenViewBase::setupScreen();
}

void ModuleScreenView::tearDownScreen()
{
    ModuleScreenViewBase::tearDownScreen();
}

void ModuleScreenView::setMeasurements(Measurement *measurements[], uint8_t nMeasurements)
{
    reset();
    hideUnusedTiles(nMeasurements);

    if (nMeasurements == 0) return;
    measurementTile0.setLabel(measurements[0]->getName());
    measurementTile0.setValue(measurements[0]->getValue(), measurements[0]->getType());

    if (nMeasurements == 1) return;
    measurementTile1.setLabel(measurements[1]->getName());
    measurementTile1.setValue(measurements[1]->getValue(), measurements[1]->getType());

    if (nMeasurements == 2) return;
    measurementTile2.setLabel(measurements[2]->getName());
    measurementTile2.setValue(measurements[2]->getValue(), measurements[2]->getType());

    if (nMeasurements == 3) return;
    measurementTile3.setLabel(measurements[3]->getName());
    measurementTile3.setValue(measurements[3]->getValue(), measurements[3]->getType());
}

void ModuleScreenView::setSelected(uint8_t index)
{
    measurementTile0.setSelected(index == 0);
    measurementTile1.setSelected(index == 1);
    measurementTile2.setSelected(index == 2);
    measurementTile3.setSelected(index == 3);
}

void ModuleScreenView::setTitle(char const *name)
{
    Unicode::strncpy(moduleNameBuffer, name, MODULENAME_SIZE);
    moduleName.invalidate();
}

void ModuleScreenView::hideUnusedTiles(uint8_t nTilesUsed) 
{
    if (nTilesUsed == 4) return;

    if (nTilesUsed < 4) {
        measurementTile3.setVisible(false);
    }

    if (nTilesUsed < 3) {
        measurementTile2.setVisible(false);
    }

    if (nTilesUsed < 2) {
        measurementTile1.setVisible(false);
    }

    if (nTilesUsed < 1) {
        measurementTile0.setVisible(false);
    }
}

void ModuleScreenView::reset() 
{
    measurementTile0.setVisible(true);
    measurementTile1.setVisible(true);
    measurementTile2.setVisible(true);
    measurementTile3.setVisible(true);
}
