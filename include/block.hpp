#pragma once
#include <draw.h>
#include <camera.h>
#include <vector>
#include <memory>

class Block
{
public:
    short x, y;

    Block(short x, short y);
    virtual void draw(Camera cam) = 0;
};

class GrassBlock : public Block
{
public:
    GrassBlock(short x, short y);
    void draw(Camera cam) override;
};

class DirtBlock : public Block
{
public:
    DirtBlock(short x, short y);
    void draw(Camera cam) override;
};

class StoneBlock : public Block
{
public:
    StoneBlock(short x, short y);
    void draw(Camera cam) override;
};

typedef std::vector<std::unique_ptr<Block>> BlockList;