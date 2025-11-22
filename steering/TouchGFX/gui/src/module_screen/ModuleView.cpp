#include <gui/module_screen/ModuleView.hpp>

ModuleView::ModuleView()
{

}

void ModuleView::setupScreen()
{
    ModuleViewBase::setupScreen();
}

void ModuleView::tearDownScreen()
{
    ModuleViewBase::tearDownScreen();
}

void ModuleView::setMeasurements(Measurement *measurements, uint8_t nMeasurements)
{
    reset();
    hideUnusedTiles(nMeasurements);

    if (nMeasurements == 0) return;
    measurementTile0.setLabel(measurements[0].getName());
    measurementTile0.setValue(measurements[0].getValue(), measurements[0].getType());

    if (nMeasurements == 1) return;
    measurementTile1.setLabel(measurements[1].getName());
    measurementTile1.setValue(measurements[1].getValue(), measurements[1].getType());

    if (nMeasurements == 2) return;
    measurementTile2.setLabel(measurements[2].getName());
    measurementTile2.setValue(measurements[2].getValue(), measurements[2].getType());

    if (nMeasurements == 3) return;
    measurementTile3.setLabel(measurements[3].getName());
    measurementTile3.setValue(measurements[3].getValue(), measurements[3].getType());

    if (nMeasurements == 4) return;
    measurementTile4.setLabel(measurements[4].getName());
    measurementTile4.setValue(measurements[4].getValue(), measurements[4].getType());

    if (nMeasurements == 5) return;
    measurementTile5.setLabel(measurements[5].getName());
    measurementTile5.setValue(measurements[5].getValue(), measurements[5].getType());

    if (nMeasurements == 6) return;
    measurementTile6.setLabel(measurements[6].getName());
    measurementTile6.setValue(measurements[6].getValue(), measurements[6].getType());

    if (nMeasurements == 7) return;
    measurementTile7.setLabel(measurements[7].getName());
    measurementTile7.setValue(measurements[7].getValue(), measurements[7].getType());

    if (nMeasurements == 8) return;
    measurementTile8.setLabel(measurements[8].getName());
    measurementTile8.setValue(measurements[8].getValue(), measurements[8].getType());

    if (nMeasurements == 9) return;
    measurementTile9.setLabel(measurements[9].getName());
    measurementTile9.setValue(measurements[9].getValue(), measurements[9].getType());
}

void ModuleView::setSelected(uint8_t index)
{
    measurementTile0.setSelected(index == 0);
    measurementTile1.setSelected(index == 0);
    measurementTile2.setSelected(index == 1);
    measurementTile3.setSelected(index == 1);
    measurementTile4.setSelected(index == 2);
    measurementTile5.setSelected(index == 2);
    measurementTile6.setSelected(index == 3);
    measurementTile7.setSelected(index == 3);
    measurementTile8.setSelected(index == 4);
    measurementTile9.setSelected(index == 4);
}

void ModuleView::setTitle(char const *name)
{
    Unicode::strncpy(moduleNameBuffer, name, MODULENAME_SIZE);
    moduleName.invalidate();
}

void ModuleView::hideUnusedTiles(uint8_t nTilesUsed) 
{
    if (nTilesUsed == 10) return;

    if (nTilesUsed < 10) {
        measurementTile9.setVisible(false);
    }

    if (nTilesUsed < 9) {
        measurementTile8.setVisible(false);
    }

    if (nTilesUsed < 8) {
        measurementTile7.setVisible(false);
    }

    if (nTilesUsed < 7) {
        measurementTile6.setVisible(false);
    }

    if (nTilesUsed < 6) {
        measurementTile5.setVisible(false);
    }

    if (nTilesUsed < 5) {
        measurementTile4.setVisible(false);
    }

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

void ModuleView::reset() 
{
    measurementTile0.setVisible(true);
    measurementTile1.setVisible(true);
    measurementTile2.setVisible(true);
    measurementTile3.setVisible(true);
    measurementTile4.setVisible(true);
    measurementTile5.setVisible(true);
    measurementTile6.setVisible(true);
    measurementTile7.setVisible(true);
    measurementTile8.setVisible(true);
    measurementTile9.setVisible(true);
}
