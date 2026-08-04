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

void ModuleView::setSensors(sensor_meta_t *sensors, uint16_t nSensors)
{
    reset();
    hideUnusedTiles(nSensors);

    if (nSensors == 0) return;
    sensorTile0.setLabel(sensors[0].name);
    sensorTile0.setValue(g_sensor_values[sensors[0].global_idx]);

    if (nSensors == 1) return;
    sensorTile1.setLabel(sensors[1].name);
    sensorTile1.setValue(g_sensor_values[sensors[1].global_idx]);
    if (nSensors == 2) return;
    sensorTile2.setLabel(sensors[2].name);
    sensorTile2.setValue(g_sensor_values[sensors[2].global_idx]);

    if (nSensors == 3) return;
    sensorTile3.setLabel(sensors[3].name);
    sensorTile3.setValue(g_sensor_values[sensors[3].global_idx]);

    if (nSensors == 4) return;
    sensorTile4.setLabel(sensors[4].name);
    sensorTile4.setValue(g_sensor_values[sensors[4].global_idx]);

    if (nSensors == 5) return;
    sensorTile5.setLabel(sensors[5].name);
    sensorTile5.setValue(g_sensor_values[sensors[5].global_idx]);

    if (nSensors == 6) return;
    sensorTile6.setLabel(sensors[6].name);
    sensorTile6.setValue(g_sensor_values[sensors[6].global_idx]);

    if (nSensors == 7) return;
    sensorTile7.setLabel(sensors[7].name);
    sensorTile7.setValue(g_sensor_values[sensors[7].global_idx]);

    if (nSensors == 8) return;
    sensorTile8.setLabel(sensors[8].name);
		sensorTile8.setValue(g_sensor_values[sensors[8].global_idx]);

    if (nSensors == 9) return;
    sensorTile9.setLabel(sensors[9].name);
		sensorTile9.setValue(g_sensor_values[sensors[9].global_idx]);
}

void ModuleView::setSelected(uint8_t index)
{
    sensorTile0.setSelected(index == 0);
    sensorTile1.setSelected(index == 0);
    sensorTile2.setSelected(index == 1);
    sensorTile3.setSelected(index == 1);
    sensorTile4.setSelected(index == 2);
    sensorTile5.setSelected(index == 2);
    sensorTile6.setSelected(index == 3);
    sensorTile7.setSelected(index == 3);
    sensorTile8.setSelected(index == 4);
    sensorTile9.setSelected(index == 4);
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
        sensorTile9.setVisible(false);
    }

    if (nTilesUsed < 9) {
        sensorTile8.setVisible(false);
    }

    if (nTilesUsed < 8) {
        sensorTile7.setVisible(false);
    }

    if (nTilesUsed < 7) {
        sensorTile6.setVisible(false);
    }

    if (nTilesUsed < 6) {
        sensorTile5.setVisible(false);
    }

    if (nTilesUsed < 5) {
        sensorTile4.setVisible(false);
    }

    if (nTilesUsed < 4) {
        sensorTile3.setVisible(false);
    }

    if (nTilesUsed < 3) {
        sensorTile2.setVisible(false);
    }

    if (nTilesUsed < 2) {
        sensorTile1.setVisible(false);
    }

    if (nTilesUsed < 1) {
        sensorTile0.setVisible(false);
    }
}

void ModuleView::reset() 
{
    sensorTile0.setVisible(true);
    sensorTile1.setVisible(true);
    sensorTile2.setVisible(true);
    sensorTile3.setVisible(true);
    sensorTile4.setVisible(true);
    sensorTile5.setVisible(true);
    sensorTile6.setVisible(true);
    sensorTile7.setVisible(true);
    sensorTile8.setVisible(true);
    sensorTile9.setVisible(true);
}
