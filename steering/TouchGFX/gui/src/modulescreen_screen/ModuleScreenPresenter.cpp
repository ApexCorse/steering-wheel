#include <gui/modulescreen_screen/ModuleScreenView.hpp>
#include <gui/modulescreen_screen/ModuleScreenPresenter.hpp>

#include <algorithm>

ModuleScreenPresenter::ModuleScreenPresenter(ModuleScreenView& v)
    : view(v)
{

}

void ModuleScreenPresenter::activate()
{
    model->initModuleMenu();
    model->initModuleTitle();
}

void ModuleScreenPresenter::deactivate()
{

}

void ModuleScreenPresenter::setMeasurements(Measurement *measurements[], uint8_t nMeasurements)
{
    this->nMeasurements = nMeasurements;

    for (uint8_t i = 0; i < nMeasurements; ++i) {
        this->measurements[i] = measurements[i];
    }

    currentIndex = static_cast<uint8_t>(0);
    firstTileIndex = static_cast<uint8_t>(0);

    lastTileIndex = static_cast<uint8_t>(
        std::min(
            static_cast<int>(nMeasurements) - 1,
            static_cast<int>(NUM_TILES_TO_SHOW) - 1
        )
    );

    updateMeasurementTilesInView();
    setSelected();
}

void ModuleScreenPresenter::setModuleTitle(char const *name)
{
    view.setTitle(name);
}

void ModuleScreenPresenter::handleButtonDown()
{
    if (!nMeasurements) return;

    currentIndex = static_cast<uint8_t>(
        std::min(
            static_cast<int>(currentIndex) + 2,
            static_cast<int>(nMeasurements) - 1
        )
    );

    adaptIndexes();
    updateMeasurementTilesInView();
    setSelected();
}

void ModuleScreenPresenter::handleButtonUp()
{
    if (!nMeasurements) return;

    currentIndex = static_cast<uint8_t>(
        std::max(
            static_cast<int>(currentIndex) - 2,
            0
        )
    );

    adaptIndexes();
    updateMeasurementTilesInView();
    setSelected();
}

void ModuleScreenPresenter::handleButtonBack()
{
    
}

void ModuleScreenPresenter::adaptIndexes()
{
    if (!nMeasurements) {
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

    if (lastTileIndex >= nMeasurements) {
        lastTileIndex = static_cast<uint8_t>(nMeasurements - 1);
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
                static_cast<int>(nMeasurements) - 1,
                static_cast<int>(NUM_TILES_TO_SHOW) - 1
            )
        );
    }
}

void ModuleScreenPresenter::updateMeasurementTilesInView()
{
    uint8_t actualFirst = static_cast<uint8_t>(
        std::max(0, static_cast<int>(firstTileIndex))
    );
    uint8_t actualLast = static_cast<uint8_t>(
        std::min(
            static_cast<int>(nMeasurements) - 1,
            static_cast<int>(lastTileIndex)
        )
    );

    Measurement *arrayToPass[static_cast<size_t>(actualLast - actualFirst + 1)];
    if (actualFirst <= actualLast && nMeasurements > 0) {
        for (uint8_t i = actualFirst; i <= actualLast; ++i) {
            arrayToPass[i - actualFirst] = measurements[i];
        }
    }

    view.setMeasurements(arrayToPass, static_cast<uint8_t>(actualLast - actualFirst + 1));
}

void ModuleScreenPresenter::setSelected()
{
    view.setSelected(static_cast<uint8_t>(currentIndex - firstTileIndex));
}
