#include <gui/menuscreen_screen/MenuScreenView.hpp>
#include <gui/menuscreen_screen/MenuScreenPresenter.hpp>

#include <algorithm>
#include <cstring>

MenuScreenPresenter::MenuScreenPresenter(MenuScreenView& v)
    : view(v), currentIndex(0), firstTileIndex(0), lastTileIndex(4)
{

}

void MenuScreenPresenter::activate()
{
    model->initSections();
}

void MenuScreenPresenter::deactivate()
{

}

void MenuScreenPresenter::setSections(Section *sections[], uint8_t nSections)
{
    this->nSections = nSections;

    for (int i = 0; i < nSections; ++i) {
        this->sections[i] = sections[i];
    }

    currentIndex = 0; 
    firstTileIndex = 0;
   
    lastTileIndex = static_cast<uint8_t>(
        std::min(
            static_cast<int>(nSections) - 1, 
            static_cast<int>(NUM_TILES_TO_SHOW) - 1
        )
    );

    updateSectionTilesInView();
    setSelected();
}

void MenuScreenPresenter::handleButtonDown()
{
    if (!nSections) return;

    currentIndex = static_cast<uint8_t>(
        std::min(
            static_cast<int>(currentIndex) + 1,
            static_cast<int>(nSections) - 1
        )
    );

    adaptIndexes();
    updateSectionTilesInView();
    setSelected();
}

void MenuScreenPresenter::handleButtonUp()
{
    if (!nSections) return;

    currentIndex = static_cast<uint8_t>(
        std::max(
            static_cast<int>(currentIndex) - 1,
            0
        )
    );

    adaptIndexes();
    updateSectionTilesInView();
    setSelected();
}

void MenuScreenPresenter::handleButtonConfirm()
{
    if (currentIndex < static_cast<uint8_t>(0) || currentIndex >= nSections) return;

    if (sections[currentIndex] == nullptr) return;

    if (strcmp(sections[currentIndex]->getName(), "Drive") == 0) {
        view.gotoDriveScreen();
    } else if (strcmp(sections[currentIndex]->getName(), "Start Up") == 0) {
        view.gotoStartUpScreen();
    } else {
        model->setChosenSection(sections[currentIndex]->getName());
        view.gotoSectionScreen();
    }
}

void MenuScreenPresenter::handleButtonBack()
{
    
}

void MenuScreenPresenter::adaptIndexes()
{
    if (!nSections) {
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
            static_cast<int>(currentIndex) - static_cast<int>(NUM_TILES_TO_SHOW) - 1
        );
        lastTileIndex = currentIndex;
    }

    if (lastTileIndex >= nSections) {
        lastTileIndex = static_cast<uint8_t>(nSections - 1);
        firstTileIndex = static_cast<uint8_t>(
            std::max(
                0,
                static_cast<int>(lastTileIndex) - static_cast<int>(NUM_TILES_TO_SHOW) - 1
            )
        );
    }
    if (firstTileIndex < static_cast<uint8_t>(0)) {
        firstTileIndex = static_cast<uint8_t>(0);
        lastTileIndex = static_cast<uint8_t>(
            std::min(
                static_cast<int>(nSections) - 1,
                static_cast<int>(NUM_TILES_TO_SHOW) - 1
            )
        );
    }
}

void MenuScreenPresenter::updateSectionTilesInView()
{
    uint8_t actualFirst = static_cast<uint8_t>(
        std::max(0, static_cast<int>(firstTileIndex))
    );
    uint8_t actualLast = static_cast<uint8_t>(
        std::min(
            static_cast<int>(nSections) - 1,
            static_cast<int>(lastTileIndex)
        )
    );

    Section *arrayToPass[static_cast<size_t>(actualLast - actualFirst + 1)];
    if (actualFirst <= actualLast && nSections > 0) {
        for (uint8_t i = actualFirst; i <= actualLast; ++i) {
            arrayToPass[i - actualFirst] = sections[i];
        }
    }

    view.setSections(arrayToPass, static_cast<uint8_t>(actualLast - actualFirst + 1));
}

void MenuScreenPresenter::setSelected()
{
    view.setSelected(currentIndex - firstTileIndex);
}
