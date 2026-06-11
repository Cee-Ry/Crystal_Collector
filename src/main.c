#include "raylib.h"

int main() {
  InitWindow(1280, 720, "CRYSTAL COLLECTOR");

  Texture2D menu_bg = LoadTexture("assets/textures/backgrounds/menu_bg.png");

  while (!WindowShouldClose()) {
    BeginDrawing();

    DrawTexturePro(
      menu_bg,
      (Rectangle){ 0, 0, menu_bg.width, menu_bg.height }, 
      (Rectangle){ 0, 0, GetScreenWidth(), GetScreenHeight() },
      (Vector2){ 0, 0 },  
      0.0f,              
      WHITE             
    );

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
