#include <gui/section_screen/SectionView.hpp>

SectionView::SectionView()
{

}

void SectionView::setupScreen()
{
    SectionViewBase::setupScreen();
}

void SectionView::tearDownScreen()
{
    SectionViewBase::tearDownScreen();
}

void SectionView::setModules(module_meta_t *modules, uint16_t nModules)
{
    reset();
    hideUnusedTiles(nModules);

    if (nModules == 0) return;
    moduleTile0.setText(modules[0].name);

    if (nModules == 1) return;
    moduleTile1.setText(modules[1].name);

    if (nModules == 2) return;
    moduleTile2.setText(modules[2].name);

    if (nModules == 3) return;
    moduleTile3.setText(modules[3].name);

    if (nModules == 4) return;
    moduleTile4.setText(modules[4].name);
}

void SectionView::setSelected(uint16_t index)
{
    moduleTile0.setSelected(index == 0);
    moduleTile1.setSelected(index == 1);
    moduleTile2.setSelected(index == 2);
    moduleTile3.setSelected(index == 3);
    moduleTile4.setSelected(index == 4);
}

void SectionView::setTitle(char const *name)
{
    Unicode::strncpy(sectionNameBuffer, name, SECTIONNAME_SIZE);
    sectionName.invalidate();
}

void SectionView::hideUnusedTiles(uint16_t nTilesUsed) 
{
    if (nTilesUsed == 5) return;

    if (nTilesUsed < 5) {
        moduleTile4.setVisible(false);
    }

    if (nTilesUsed < 4) {
        moduleTile3.setVisible(false);
    }

    if (nTilesUsed < 3) {
        moduleTile2.setVisible(false);
    }

    if (nTilesUsed < 2) {
        moduleTile1.setVisible(false);
    }

    if (nTilesUsed < 1) {
        moduleTile0.setVisible(false);
    }
}

void SectionView::reset() 
{
    moduleTile0.setVisible(true);
    moduleTile1.setVisible(true);
    moduleTile2.setVisible(true);
    moduleTile3.setVisible(true);
    moduleTile4.setVisible(true);
}
