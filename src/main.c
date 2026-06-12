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
    DrawTexturePro(
      menu_bg,
      (Rectangle){ 0, 0, menu_bg.width, menu_bg.height }, 
      (Rectangle){ 0, 0, GetScreenWidth(), GetScreenHeight() },
      (Vector2){ 0, 0 },  
      0.0f,              
      GRAY             
    );

    DrawTexture(title, ((WIDTH / 2) - (title.width / 2)), 25, WHITE);
    
    int distance = 0;
    for (int i = 0; i < 4; i++) {
      float x = (WIDTH / 2) - (buttons[i].width / 2);
      float y = (HEIGHT / 2) + distance;

      Rectangle bounds = { x, y, buttons[i].width, buttons[i].height };
      bool hovered = CheckCollisionPointRec(GetMousePosition(), bounds);

      if (hovered) {
        DrawTexturePro(
          buttons[i],
          (Rectangle){ 0, 0, buttons[i].width, buttons[i].height}, 
          (Rectangle){ x - 8, y - 8, buttons[i].width + 16, buttons[i].height + 16}, 
          (Vector2){ 0, 0 },  
          0.0f,              
          (Color){ 0, 255, 255, 255 }
        );
      } else {
        DrawTexture(buttons[i], x, y, WHITE);
      }
        
      distance += 90;
    }

    BeginDrawing();
    EndDrawing();
  }

  for (int i = 0; i < 4; i++) UnloadTexture(buttons[i]);
  UnloadTexture(title);
  UnloadTexture(menu_bg);
  CloseWindow();
  return 0;
}
