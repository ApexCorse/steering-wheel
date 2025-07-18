#include <gui/sectionscreen_screen/SectionScreenView.hpp>
#include <gui/sectionscreen_screen/SectionScreenPresenter.hpp>

#include <algorithm>

SectionScreenPresenter::SectionScreenPresenter(SectionScreenView& v)
    : view(v)
{

}

void SectionScreenPresenter::activate()
{
    model->initSectionMenu();
    model->initSectionTitle();
}

void SectionScreenPresenter::deactivate()
{

}

void SectionScreenPresenter::setModules(Module *modules[], uint8_t nModules)
{
    this->nModules = nModules;

    for (uint8_t i = 0; i < nModules; ++i) {
        this->modules[i] = modules[i];
    }

    currentIndex = static_cast<uint8_t>(0);
    firstTileIndex = static_cast<uint8_t>(0);

    lastTileIndex = static_cast<uint8_t>(
        std::min(
            static_cast<int>(nModules) - 1,
            static_cast<int>(NUM_TILES_TO_SHOW) - 1
        )
    );

    updateModuleTilesInView();
    setSelected();
}

void SectionScreenPresenter::setSectionTitle(char const *name)
{
    view.setTitle(name);
}

void SectionScreenPresenter::handleButtonDown()
{
    if (!nModules) return;

    currentIndex = static_cast<uint8_t>(
        std::min(
            static_cast<int>(currentIndex) + 1,
            static_cast<int>(nModules) - 1
        )
    );
    adaptIndexes();
    updateModuleTilesInView();
    setSelected();
}

void SectionScreenPresenter::handleButtonUp()
{
    if (!nModules) return;

    currentIndex = static_cast<uint8_t>(
        std::max(
            static_cast<int>(currentIndex) - 1,
            0
        )
    );
    adaptIndexes();
    updateModuleTilesInView();
    setSelected();
}

void SectionScreenPresenter::handleButtonConfirm()
{
    if (currentIndex < static_cast<uint8_t>(0) || currentIndex >= nModules) return;

    if (modules[currentIndex] == nullptr) return;

    model->setChosenModule(modules[currentIndex]->getName());
    view.gotoModuleScreen();
}

void SectionScreenPresenter::handleButtonBack()
{
    
}

void SectionScreenPresenter::adaptIndexes()
{
    if (!nModules) {
        firstTileIndex = static_cast<uint8_t>(0);
        lastTileIndex = static_cast<uint8_t>(0);
        return;
    }

    if (currentIndex < firstTileIndex) {
        firstTileIndex = currentIndex;
        lastTileIndex = static_cast<uint8_t>(
            static_cast<int>(firstTileIndex) + static_cast<int>(NUM_TILES_TO_SHOW) - 1
        );
    } else if (currentIndex > lastTileIndex) {
        firstTileIndex = static_cast<uint8_t>(
            static_cast<int>(currentIndex) - (static_cast<int>(NUM_TILES_TO_SHOW) - 1)
        );
        lastTileIndex = currentIndex;
    }

    if (lastTileIndex >= nModules) {
        lastTileIndex = static_cast<uint8_t>(nModules - 1);
        firstTileIndex = static_cast<uint8_t>(
            std::max(
                0,
                static_cast<int>(lastTileIndex) - (static_cast<int>(NUM_TILES_TO_SHOW) - 1)
            )
        );
    }
    if (firstTileIndex < static_cast<uint8_t>(0)) {
        firstTileIndex = static_cast<uint8_t>(0);
        lastTileIndex = static_cast<uint8_t>(
            std::min(
                static_cast<int>(nModules) - 1,
                static_cast<int>(NUM_TILES_TO_SHOW) - 1
            )
        );
    }
}

void SectionScreenPresenter::updateModuleTilesInView()
{
    uint8_t actualFirst = static_cast<uint8_t>(
        std::max(0, static_cast<int>(firstTileIndex))
    );
    uint8_t actualLast = static_cast<uint8_t>(
        std::min(
            static_cast<int>(nModules) - 1,
            static_cast<int>(lastTileIndex)
        )
    );

    Module *arrayToPass[static_cast<size_t>(actualLast - actualFirst + 1)];
    if (actualFirst <= actualLast && nModules > 0) {
        for (uint8_t i = actualFirst; i <= actualLast; ++i) {
            arrayToPass[i - actualFirst] = modules[i];
        }
    }

    view.setModules(arrayToPass, static_cast<uint8_t>(actualLast - actualFirst + 1));
}

void SectionScreenPresenter::setSelected()
{
    view.setSelected(static_cast<uint8_t>(currentIndex - firstTileIndex));
}
