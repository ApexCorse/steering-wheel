#include <gui/menuscreen_screen/MenuScreenView.hpp>

MenuScreenView::MenuScreenView()
{
    menuTile4.setDividerVisible(false);
}

void MenuScreenView::setupScreen()
{
    MenuScreenViewBase::setupScreen();
}

void MenuScreenView::tearDownScreen()
{
    MenuScreenViewBase::tearDownScreen();
}

void MenuScreenView::setMenuTiles(std::vector<char*> menuTiles)
{
    if (menuTiles.size() == 0) return;
    menuTile0.setText(menuTiles.at(0));

    if (menuTiles.size() == 1) return;
    menuTile1.setText(menuTiles.at(1));

    if (menuTiles.size() == 2) return;
    menuTile2.setText(menuTiles.at(2));

    if (menuTiles.size() == 3) return;
    menuTile3.setText(menuTiles.at(3));

    if (menuTiles.size() == 4) return;
    menuTile4.setText(menuTiles.at(4));
}

void MenuScreenView::setSelected(int index)
{
    menuTile0.setSelected(index == 0);
    menuTile1.setSelected(index == 1);
    menuTile2.setSelected(index == 2);
    menuTile3.setSelected(index == 3);
    menuTile4.setSelected(index == 5);
}