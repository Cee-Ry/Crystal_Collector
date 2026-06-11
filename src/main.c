#include "raylib.h"

int main() {
  const int WIDTH = 1280;
  const int HEIGHT = 720;

  InitWindow(WIDTH, HEIGHT, "CRYSTAL COLLECTOR");
  SetTargetFPS(60);

  Texture2D menu_bg = LoadTexture("assets/textures/backgrounds/menu_bg.png");
  Texture2D title = LoadTexture("assets/textures/ui/titles/crystal_collector.png");
  Texture2D dim = LoadTexture("assets/textures/ui/effects/dim_effect_full.png");

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

    DrawTexturePro(
      dim,
      (Rectangle){ 0, 0, dim.width, dim.height }, 
      (Rectangle){ 0, 0, GetScreenWidth(), GetScreenHeight() },
      (Vector2){ 0, 0 },  
      0.0f,              
      WHITE             
    );

    DrawTexture(title, ((WIDTH / 2) - (title.width / 2)), 25, WHITE);

    EndDrawing();
  }

  UnloadTexture(dim);
  UnloadTexture(title);
  UnloadTexture(menu_bg);
  CloseWindow();
  return 0;
}
