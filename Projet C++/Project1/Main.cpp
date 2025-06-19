#include <iostream>
#include"GameFunction.cpp"
#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(){
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Plateau Raylib");
    SetTargetFPS(60);

    Board board;
    Player* player = new Player(100, 50, 10, { 10, 10 });
    board.setEntity(10, 10, player);

    while (!WindowShouldClose()) {
        // Mouvements
        if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_Z)) {
            Move(player, board, -1, 0);
        }
        else if (IsKeyPressed(KEY_S)) {
            Move(player, board, 1, 0);
        }
        else if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_Q)) {
            Move(player, board, 0, -1);
        }
        else if (IsKeyPressed(KEY_D)) {
            Move(player, board, 0, 1);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawBoard(board);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}