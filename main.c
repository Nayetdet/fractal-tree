#include <raylib.h>
#include <rlgl.h>

#include "design.h"
#include "slider.h"
#include "tree.h"

int main(void) {
    float angleInDegrees = 0.0;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(800, 600, "Fractal Tree");
    SetTargetFPS(60);    

    Image icon = LoadImage("assets/icon.png");
    SetWindowIcon(icon);
    UnloadImage(icon);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BACKGROUND_COLOR);

        DrawBackgroundGrid();
        DisplayCurrentAngle(angleInDegrees);
        UpdateBranchAngle(&angleInDegrees);
        DrawFractalTree(TRUNK_SIZE, angleInDegrees);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
