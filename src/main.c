#include "raylib.h"

int main() {
  const int WIDTH = 1280;
  const int HEIGHT = 720;

  InitWindow(WIDTH, HEIGHT, "Crystal Collector");
  SetTargetFPS(60);

  Texture2D menu_bg = LoadTexture("assets/textures/backgrounds/menu_bg.png");
  Texture2D title = LoadTexture("assets/textures/ui/titles/crystal_collector.png");
  Texture2D buttons[4];

  buttons[0] = LoadTexture("assets/textures/ui/buttons/play.png");
  buttons[1] = LoadTexture("assets/textures/ui/buttons/settings.png");
  buttons[2] = LoadTexture("assets/textures/ui/buttons/credits.png");
  buttons[3] = LoadTexture("assets/textures/ui/buttons/exit.png");

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

    DrawRectangle(
      0,
      0,
      GetScreenWidth(),
      GetScreenHeight(),
      (Color){0, 0, 0, 120}
    );

    DrawTexture(title, ((WIDTH / 2) - (title.width / 2)), 25, WHITE);

    int distance = 0;
    for (int i = 0; i < 4; i++) {
      DrawTexture(buttons[i], ((WIDTH / 2) - (buttons[i].width / 2)), (HEIGHT / 2) + distance, WHITE);
      distance += 90;
    }

    EndDrawing();
  }

  for (int i = 0; i < 4; i++) UnloadTexture(buttons[i]);
  UnloadTexture(title);
  UnloadTexture(menu_bg);
  CloseWindow();
  return 0;
}
