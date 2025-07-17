#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <gui/sectionscreen_screen/SectionScreenPresenter.hpp>
#include <gui/menuscreen_screen/MenuScreenPresenter.hpp>

#include <cstring>

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

void Model::setChosenModule(char const *name)
{
  strcpy(chosenModule, name);
}

void Model::tick()
{

}
