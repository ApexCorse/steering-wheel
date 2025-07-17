#include <gui/menuscreen_screen/MenuScreenView.hpp>

MenuScreenView::MenuScreenView()
{

}

void MenuScreenView::setupScreen()
{
    MenuScreenViewBase::setupScreen();
}

void MenuScreenView::tearDownScreen()
{
    MenuScreenViewBase::tearDownScreen();
}

void MenuScreenView::setMenuTiles(char *menuTiles[], int nMenuTiles)
{
    reset();
    hideUnusedTiles(nMenuTiles);
    if (nMenuTiles == 0) return;
    menuTile0.setText(menuTiles[0]);

    if (nMenuTiles == 1) return;
    menuTile1.setText(menuTiles[1]);

    if (nMenuTiles == 2) return;
    menuTile2.setText(menuTiles[2]);

    if (nMenuTiles == 3) return;
    menuTile3.setText(menuTiles[3]);

    if (nMenuTiles == 4) return;
    menuTile4.setText(menuTiles[4]);
}

void MenuScreenView::setSelected(int index)
{
    menuTile0.setSelected(index == 0);
    menuTile1.setSelected(index == 1);
    menuTile2.setSelected(index == 2);
    menuTile3.setSelected(index == 3);
    menuTile4.setSelected(index == 4);
}

void MenuScreenView::hideUnusedTiles(int nTilesUsed) {
    if (nTilesUsed == 5) return;

    if (nTilesUsed < 5) {
        menuTile4.setVisible(false);
    }

    if (nTilesUsed < 4) {
        menuTile3.setVisible(false);
    }

    if (nTilesUsed < 3) {
        menuTile2.setVisible(false);
    }

    if (nTilesUsed < 2) {
        menuTile1.setVisible(false);
    }

    if (nTilesUsed < 1) {
        menuTile0.setVisible(false);
    }
}

void MenuScreenView::reset() {
    menuTile0.setVisible(true);
    menuTile1.setVisible(true);
    menuTile2.setVisible(true);
    menuTile3.setVisible(true);
    menuTile4.setVisible(true);
}
