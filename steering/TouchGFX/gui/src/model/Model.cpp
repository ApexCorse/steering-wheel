#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <gui/section_screen/SectionPresenter.hpp>
#include <gui/menu_screen/MenuPresenter.hpp>
#include <gui/module_screen/ModulePresenter.hpp>

#include <cstring>
#include <main.h>
#include <sensor_storage.h>

Model::Model() : modelListener(0) 
{
  strcpy(chosenSection, "");
  strcpy(chosenModule, "");
  strcpy(currentScreen, "");
  strcpy(previousScreen, "Drive");
}

void Model::initSections()
{
  modelListener->setSections(g_sections, SECTION_COUNT);
}

void Model::initSectionMenu()
{  
	int section_idx = section_find_by_name(chosenSection);
  if (section_idx < 0) {
    modelListener->setModules(nullptr, 0);
    return;
  }

  modelListener->setModules(g_modules + g_sections[section_idx].module_start, g_sections[section_idx].module_count);
}

void Model::initSectionTitle()
{
  if (strcmp(chosenSection, "") == 0) {
    modelListener->setSectionTitle("Section Name");
    return;
  }
  modelListener->setSectionTitle(chosenSection);
}

void Model::initModuleMenu()
{  
	int section_idx = section_find_by_name(chosenSection);
  if (section_idx < 0) {
    modelListener->setSensors(nullptr, 0);
    return;
  }

	int module_idx = module_find_by_name(section_idx, chosenModule);
	if (module_idx < 0) {
		modelListener->setSensors(nullptr, 0);
		return;
	}

  modelListener->setSensors(g_sensors + g_modules[module_idx].sensor_start, g_modules[module_idx].sensor_count);
}

void Model::initModuleTitle()
{
  if (strcmp(chosenModule, "") == 0) {
    modelListener->setModuleTitle("Module Name");
    return;
  }
  modelListener->setModuleTitle(chosenModule);
}

void Model::setChosenSection(char const *name)
{
  strcpy(chosenSection, name);
}

void Model::setChosenModule(char const *name)
{
  strcpy(chosenModule, name);
}

void Model::tick()
{
  if (pression) timeSincePression = (timeSincePression + 1) % 60;
  if (timeSincePression > 0) return;
  pression = false;

  if (HAL_GPIO_ReadPin(GPIOA, USER_BUTTON_Pin) == GPIO_PIN_SET) {
    pression = true;
    modelListener->handleButtonConfirm();
  }
}
