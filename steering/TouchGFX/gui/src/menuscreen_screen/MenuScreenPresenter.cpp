#include <gui/menuscreen_screen/MenuScreenView.hpp>
#include <gui/menuscreen_screen/MenuScreenPresenter.hpp>

#include <cmath>

MenuScreenPresenter::MenuScreenPresenter(MenuScreenView& v)
    : view(v), currentIndex(0), firstTileIndex(0), lastTileIndex(4)
{

}

void MenuScreenPresenter::activate()
{

}

void MenuScreenPresenter::deactivate()
{

}

void MenuScreenPresenter::setMenuTiles(std::vector<char*> menuTiles)
{
    this->menuTiles = menuTiles;
    view.setMenuTiles(menuTiles);
}

void MenuScreenPresenter::handleButtonUp()
{
    currentIndex = std::max(currentIndex - 1, 0);
    adaptIndexes();

    updateMenuTilesInView();
    setSelected();
}

void MenuScreenPresenter::handleButtonDown()
{
    currentIndex = std::min(currentIndex + 1, (int)menuTiles.size() - 1);
    adaptIndexes();

    updateMenuTilesInView();
    setSelected();
}

void MenuScreenPresenter::handleButtonConfirm()
{}

void MenuScreenPresenter::handleButtonBack()
{}

void MenuScreenPresenter::adaptIndexes()
{
    if (currentIndex < firstTileIndex) {
        firstTileIndex--;
        lastTileIndex--;
    } else if (currentIndex > lastTileIndex) {
        firstTileIndex++;
        lastTileIndex++;
    }
}

void MenuScreenPresenter::updateMenuTilesInView()
{
    std::vector<char*> vectorToPass(menuTiles);

    vectorToPass.erase(vectorToPass.begin(), std::next(vectorToPass.begin(), firstTileIndex));
    vectorToPass.erase(std::next(vectorToPass.begin(), lastTileIndex), vectorToPass.end());

    view.setMenuTiles(vectorToPass);
}

void MenuScreenPresenter::setSelected()
{
    view.setSelected(currentIndex - firstTileIndex);
}