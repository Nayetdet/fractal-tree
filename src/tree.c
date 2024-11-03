#include <math.h>

#include <raylib.h>
#include <rlgl.h>

#include "design.h"

#include "tree.h"

static void DrawBranches(int size, float angleInDegrees);
static void DrawTrunk(int size);
static void DrawBranchWithRotation(int size, float angleInDegrees);

static void DrawTrunk(int size) {
    DrawLine(0, 0, 0, -size, TREE_COLOR);
    rlTranslatef(0, -size, 0);
}

static void DrawBranchWithRotation(int size, float angleInDegrees) {
    rlPushMatrix();
    rlRotatef(angleInDegrees, 0, 0, -1);
    DrawBranches(size, angleInDegrees);
    rlPopMatrix();
}

static void DrawBranches(int size, float angleInDegrees) {
    if (size <= 1) {
        return;
    }

    DrawTrunk(size);
    size *= 1 - SIZE_RATIO;

    DrawBranchWithRotation(size, +angleInDegrees); // Left branch
    DrawBranchWithRotation(size, -angleInDegrees); // Right branch
}

void DrawFractalTree(int size, float angleInDegrees) {
    rlPushMatrix();
    rlTranslatef(GetScreenWidth() / 2, GetScreenHeight(), 0);
    DrawBranches(size, angleInDegrees);
    rlPopMatrix();
}
