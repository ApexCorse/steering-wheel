#include <gui/menu_screen/MenuView.hpp>

MenuView::MenuView()
{

}

void MenuView::setupScreen()
{
    MenuViewBase::setupScreen();
}

void MenuView::tearDownScreen()
{
    MenuViewBase::tearDownScreen();
}

void MenuView::setSections(Section *sections[], uint8_t nSections)
{
    reset();
    hideUnusedTiles(nSections);
    if (nSections == 0) return;
    sectionTile0.setText(sections[0]->getName());

    if (nSections == 1) return;
    sectionTile1.setText(sections[1]->getName());

    if (nSections == 2) return;
    sectionTile2.setText(sections[2]->getName());

    if (nSections == 3) return;
    sectionTile3.setText(sections[3]->getName());

    if (nSections == 4) return;
    sectionTile4.setText(sections[4]->getName());
}

void MenuView::setSelected(int index)
{
    sectionTile0.setSelected(index == 0);
    sectionTile1.setSelected(index == 1);
    sectionTile2.setSelected(index == 2);
    sectionTile3.setSelected(index == 3);
    sectionTile4.setSelected(index == 4);
}

void MenuView::hideUnusedTiles(int nTilesUsed) {
    if (nTilesUsed == 5) return;

    if (nTilesUsed < 5) {
        sectionTile4.setVisible(false);
    }

    if (nTilesUsed < 4) {
        sectionTile3.setVisible(false);
    }

    if (nTilesUsed < 3) {
        sectionTile2.setVisible(false);
    }

    if (nTilesUsed < 2) {
        sectionTile1.setVisible(false);
    }

    if (nTilesUsed < 1) {
        sectionTile0.setVisible(false);
    }
}

void MenuView::reset() {
    sectionTile0.setVisible(true);
    sectionTile1.setVisible(true);
    sectionTile2.setVisible(true);
    sectionTile3.setVisible(true);
    sectionTile4.setVisible(true);
}
