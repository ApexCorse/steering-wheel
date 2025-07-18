#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <gui/sectionscreen_screen/SectionScreenPresenter.hpp>
#include <gui/menuscreen_screen/MenuScreenPresenter.hpp>
#include <gui/modulescreen_screen/ModuleScreenPresenter.hpp>

#include <cstring>
#include <main.h>

Model::Model() : modelListener(0), configuration(nullptr), chosenSection(""), chosenModule("")
{
  configuration = new Configuration();
}

void Model::initSections()
{
  Section *sections[SectionScreenPresenter::MAX_MODULES];
  uint8_t nSections = configuration->getNSections();

  Section *current = configuration->getFirstSection();
  uint8_t i = 0;

  while (current && nSections < MenuScreenPresenter::MAX_SECTIONS) {
    sections[i] = current;

    i++;
    current = current->next;
  }

  modelListener->setSections(sections, nSections);
}

void Model::initSectionMenu()
{  
  Module *modules[SectionScreenPresenter::MAX_MODULES];
  uint8_t nModules = 0;

  Section *section = configuration->getSectionByName(chosenSection);
  if (!section) {
    modelListener->setModules(modules, nModules);
    return;
  }

  Module *current = section->getFirstModule();
  nModules = section->getNModules();
  uint8_t i = 0;

  while (current && nModules < SectionScreenPresenter::MAX_MODULES) {
    modules[i] = current;

    i++;
    current = current->next;
  }

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
  Measurement *measurements[ModuleScreenPresenter::MAX_MEASUREMENTS];
  uint8_t nMeasurements = 0;

  Section *section = configuration->getSectionByName(chosenSection);
  if (!section) {
    modelListener->setMeasurements(measurements, nMeasurements);
    return;
  }

  Module *module_ = section->getModuleByName(chosenModule);
  if (!module_) {
    modelListener->setMeasurements(measurements, nMeasurements);
    return;
  }

  Measurement *current = module_->getFirstMeasurement();
  nMeasurements = module_->getNMeasurements();
  uint8_t i = 0;

  while (current && nMeasurements < ModuleScreenPresenter::MAX_MEASUREMENTS) {
    measurements[i] = current;

    i++;
    current = current->next;
  }

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
  if (HAL_GPIO_ReadPin(GPIOA, USER_BUTTON_Pin) == GPIO_PIN_SET) {
    modelListener->handleButtonConfirm();
  }
}
