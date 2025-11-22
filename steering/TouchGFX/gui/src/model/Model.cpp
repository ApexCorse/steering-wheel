#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <gui/section_screen/SectionPresenter.hpp>
#include <gui/menu_screen/MenuPresenter.hpp>
#include <gui/module_screen/ModulePresenter.hpp>

#include <cstring>
#include <main.h>

Model::Model() : modelListener(0), configuration(nullptr) 
{
  strcpy(chosenSection, "");
  strcpy(chosenModule, "");
  strcpy(currentScreen, "");
  strcpy(previousScreen, "Drive");

  configuration = Configuration::instance();
}

void Model::initSections()
{
  uint8_t nSections = configuration->getNSections();
  Section *sections = configuration->getSections();

  modelListener->setSections(sections, nSections);
}

void Model::initSectionMenu()
{  
  Section *section = configuration->getSectionByName(chosenSection);
  if (!section) {
    modelListener->setModules(nullptr, 0);
    return;
  }

  Module *modules = section->getModules();
  uint8_t nModules = section->getNModules();

  modelListener->setModules(modules, nModules);
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
  Section *section = configuration->getSectionByName(chosenSection);
  if (!section) {
    modelListener->setMeasurements(nullptr, 0);
    return;
  }

  Module *module_ = section->getModuleByName(chosenModule);
  if (!module_) {
    modelListener->setMeasurements(nullptr, 0);
    return;
  }

  Measurement *measurements = module_->getMeasurements();
  uint8_t nMeasurements = module_->getNMeasurements();

  modelListener->setMeasurements(measurements, nMeasurements);
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
