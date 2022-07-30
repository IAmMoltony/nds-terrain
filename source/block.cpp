#include <block.hpp>

Block::Block(short x, short y)
{
    this->x = x;
    this->y = y;
}

//-------------------------------

GrassBlock::GrassBlock(short x, short y) : Block(x, y)
{
}

void GrassBlock::draw(Camera cam)
{
    fillRect(x - cam.x, y - cam.y, 8, 8, RGB8(127, 51, 0));
    fillRect(x - cam.x, y - cam.y, 8, 3, RGB15(0, 31, 0));
}

//-------------------------------

DirtBlock::DirtBlock(short x, short y) : Block(x, y)
{
}

void DirtBlock::draw(Camera cam)
{
    fillRect(x - cam.x, y - cam.y, 8, 8, RGB8(127, 51, 0));
}

//-------------------------------

StoneBlock::StoneBlock(short x, short y) : Block(x, y)
{
}

void StoneBlock::draw(Camera cam)
{
    fillRect(x - cam.x, y - cam.y, 8, 8, RGB15(15, 15, 15));
}