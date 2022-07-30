#include <nds.h>
#include <stdio.h>
#include <time.h>
#include <block.hpp>
#include <PerlinNoise.hpp>

int main(void)
{
    srand(time(NULL));
    consoleDemoInit();
    printf("Terrain generation test\n\nPowered by:\nhttps://github.com/Reputeless/PerlinNoise");

    videoSetMode(MODE_5_3D);
    glScreen2D();

    BlockList blocks;
    Camera cam = {0, 0};

    const siv::PerlinNoise::seed_type seed = (u32)time(NULL);
    const siv::BasicPerlinNoise<float> perlin{seed};
    for (int i = 0; i < SCREEN_WIDTH / 8; ++i)
    {
        short y = floor(perlin.noise1D_01(i) * 4.8f) * 8;
        blocks.emplace_back(new GrassBlock(i * 8, SCREEN_HEIGHT / 2 - y));

        for (short j = 1; j < 4; ++j)
            blocks.emplace_back(new DirtBlock(i * 8, SCREEN_HEIGHT / 2 - y + j * 8));
        
        for (short j = 4; j < 8; ++j)
            blocks.emplace_back(new StoneBlock(i * 8, SCREEN_HEIGHT / 2 - y + j * 8));
    }

    while (true)
    {
        scanKeys();
        u32 keys = keysHeld();
        if (keys & KEY_LEFT)
            --cam.x;
        if (keys & KEY_RIGHT)
            ++cam.x;
        if (keys & KEY_UP)
            --cam.y;
        if (keys & KEY_DOWN)
            ++cam.y;

        glBegin2D();
        glBoxFilled(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, RGB8(100, 149, 255));

        for (auto &block : blocks)
            block->draw(cam);

        glEnd2D();
        glFlush(0);

        swiWaitForVBlank();
    }

    return 0;
}