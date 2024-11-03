#include <raylib.h>

#include "design.h"

#include "slider.h"

void DisplayCurrentAngle(float angle) {
    DrawText(TextFormat("Angle: %.2f°", angle), 10, 10, 20, TREE_COLOR);
}

void UpdateBranchAngle(float* angle) {
    if (IsKeyDown(KEY_UP)) {
        *angle += ANGLE_INCREMENT;
        if (*angle >= 360) {
            *angle = 0;
        }
    }

    if (IsKeyDown(KEY_DOWN)) {
        *angle -= ANGLE_INCREMENT;
        if (*angle < 0) {
            *angle = 359;
        }
    }
}
