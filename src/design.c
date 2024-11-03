#include <raylib.h>

#include "design.h"

const Color BACKGROUND_COLOR =  {27, 32, 33, 255};
const Color TREE_COLOR = {234, 99, 140, 255};
const Color CELL_BORDER_COLOR = {48, 52, 63, 50};

void DrawBackgroundGrid(void) {
    int width = GetScreenWidth();
    int height = GetScreenHeight();

    for (int i = 0; i < width; i += CELL_SIZE)
        DrawLine(0, i, width, i, CELL_BORDER_COLOR);

    for (int i = 0; i < height; i += CELL_SIZE)
        DrawLine(i, 0, i, height, CELL_BORDER_COLOR);

    DrawRectangleLines(0, 0, width, height, CELL_BORDER_COLOR);
}
