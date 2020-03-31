#include "LibraryItem.h"

LibraryItem::LibraryItem(const std::string& date, Game* game)
    : game(game), purchased(date)
{
}

LibraryItem::~LibraryItem()
{
}
