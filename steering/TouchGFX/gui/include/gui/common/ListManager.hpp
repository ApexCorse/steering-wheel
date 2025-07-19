#ifndef LISTMANAGER_HPP
#define LISTMANAGER_HPP

#include <cstdint>
#include <algorithm>

template <typename T>
class ListManager {
public:
  static const uint8_t MAX_ITEMS = 64;

  void setItems(T *items[], uint8_t nItems)
  {
    this->nItems = nItems;

    for (uint8_t i = 0; i < nItems; ++i) {
        this->items[i] = items[i];
    }

    currentIndex = static_cast<uint8_t>(0);
    firstTileIndex = static_cast<uint8_t>(0);

    lastTileIndex = static_cast<uint8_t>(
        std::min(
            static_cast<int>(nItems) - 1,
            static_cast<int>(maxTiles) - 1
        )
    );

    _updateItemTilesInView();
    setSelected();
  }

  void handleButtonDown()
  {
    if (!nItems) return;

    currentIndex = static_cast<uint8_t>(
        std::min(
            static_cast<int>(currentIndex) + scrollAmount(),
            static_cast<int>(nItems) - 1
        )
    );

    adaptIndexes();
    _updateItemTilesInView();
    setSelected();
  }

  void handleButtonUp()
  {
    if (!nItems) return;

    currentIndex = static_cast<uint8_t>(
        std::max(
            static_cast<int>(currentIndex) - scrollAmount(),
            0
        )
    );

    adaptIndexes();
    _updateItemTilesInView();
    setSelected();
  }

  virtual void handleButtonConfirm() {}
  virtual void handleButtonBack() {}
protected:
  ListManager(uint8_t maxTiles) : maxTiles(maxTiles) {}

  T *items[MAX_ITEMS];
  uint8_t nItems;

  uint8_t currentIndex;
  uint8_t firstTileIndex;
  uint8_t lastTileIndex;

  virtual void updateItemTilesInView(T *items[], uint8_t nItems);
  virtual void setSelected();

  virtual int scrollAmount() { return 1; }

private:
  uint8_t maxTiles;

  void adaptIndexes()
  {
    if (!nItems) {
        firstTileIndex = static_cast<uint8_t>(0);
        lastTileIndex = static_cast<uint8_t>(0);
        return;
    }

    if (currentIndex < firstTileIndex) {
        firstTileIndex = currentIndex;
        lastTileIndex = static_cast<uint8_t>(
            static_cast<int>(firstTileIndex) + static_cast<int>(maxTiles) - 1
        );
    } else if (currentIndex > lastTileIndex) {
        firstTileIndex = static_cast<uint8_t>(
            static_cast<int>(currentIndex) - static_cast<int>(maxTiles) - 1
        );
        lastTileIndex = currentIndex;
    }

    if (lastTileIndex >= nItems) {
        lastTileIndex = static_cast<uint8_t>(nItems - 1);
        firstTileIndex = static_cast<uint8_t>(
            std::max(
                0,
                static_cast<int>(lastTileIndex) - static_cast<int>(maxTiles) - 1
            )
        );
    }
    if (firstTileIndex < static_cast<uint8_t>(0)) {
        firstTileIndex = static_cast<uint8_t>(0);
        lastTileIndex = static_cast<uint8_t>(
            std::min(
                static_cast<int>(nItems) - 1,
                static_cast<int>(maxTiles) - 1
            )
        );
    }
  }
  
  void _updateItemTilesInView()
  {
    uint8_t actualFirst = static_cast<uint8_t>(
        std::max(0, static_cast<int>(firstTileIndex))
    );
    uint8_t actualLast = static_cast<uint8_t>(
        std::min(
            static_cast<int>(nItems) - 1,
            static_cast<int>(lastTileIndex)
        )
    );

    T *arrayToPass[static_cast<size_t>(actualLast - actualFirst + 1)];
    if (actualFirst <= actualLast && nItems > 0) {
        for (uint8_t i = actualFirst; i <= actualLast; ++i) {
            arrayToPass[i - actualFirst] = items[i];
        }
    }

    updateItemTilesInView(arrayToPass, static_cast<uint8_t>(actualLast - actualFirst + 1));
  }
};

#endif // LISTMANAGER_HPP
