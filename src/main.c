#include "raylib.h"

int main() {
  const int WIDTH = 1024;
  const int HEIGHT = 576;
  bool run = true;
  bool playing = false;
  int state = 0;

  // SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(WIDTH, HEIGHT, "Crystal Collector");
  SetTargetFPS(40);

  //menu
  Texture2D menu_bg = LoadTexture("assets/textures/backgrounds/menu_bg.png");
  Texture2D title = LoadTexture("assets/textures/ui/titles/crystal_collector.png");
  Texture2D buttons[5];

  buttons[0] = LoadTexture("assets/textures/ui/buttons/play.png");
  buttons[1] = LoadTexture("assets/textures/ui/buttons/settings.png");
  buttons[2] = LoadTexture("assets/textures/ui/buttons/credits.png");
  buttons[3] = LoadTexture("assets/textures/ui/buttons/exit.png");
  buttons[4] = LoadTexture("assets/textures/ui/buttons/back.png");

  // credits
  Texture2D credits = LoadTexture("assets/textures/ui/dashboards/credits.png");
  Texture2D credits_title = LoadTexture("assets/textures/ui/titles/credits_txt.png");

  // play mode textures
  Texture2D player_idle = LoadTexture("assets/textures/player/idle.png");
  Texture2D player_walk = LoadTexture("assets/textures/player/idle.png");

  while (run) {
    int maxwidth = GetScreenWidth();
    int maxheight = GetScreenHeight();

    BeginDrawing();
    ClearBackground(BLACK);

    if (!playing) {
    DrawTexturePro(
        menu_bg,
        (Rectangle){ 0, 0, menu_bg.width, menu_bg.height }, 
        (Rectangle){ 0, 0, GetScreenWidth(), GetScreenHeight() },
        (Vector2){ 0, 0 },  
        0.0f,              
        GRAY             
      );
    }

    if (state == 0) {
    DrawTexture(title, (maxwidth / 2) - (title.width / 2), 20, WHITE);
    char *msg = "2nd GUI Project! Version 0.3.1";
    DrawText(msg, (GetScreenWidth() / 2) - (MeasureText(msg, 20) / 2), title.height + 28, 20, WHITE);
    
    int distance = 0;
    for (int i = 0; i < 4; i++) {
      int x = (maxwidth / 2) - (buttons[i].width / 2);
      int y = maxheight - (90 * 4) + distance;

      Rectangle bounds = { x, y, buttons[i].width, buttons[i].height };
      bool hovered = CheckCollisionPointRec(GetMousePosition(), bounds);
      bool clicked = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

      if (hovered) {
        DrawTexturePro(
          buttons[i],
          (Rectangle){ 0, 0, buttons[i].width, buttons[i].height}, 
          (Rectangle){ x - 8, y - 8, buttons[i].width + 16, buttons[i].height + 16}, 
          (Vector2){ 0, 0 },  
          0.0f,              
          (Color){ 0, 255, 255, 255 }
          );

        if (clicked && i == 0) state = 1;
        if (clicked && i == 1) state = 2;
        if (clicked && i == 2) state = 3;
        else if (clicked && i == 3) state = 4;
      } else {
        DrawTexture(buttons[i], x, y, WHITE);
      }
        
      distance += 90;
    }
    }

    int x = (maxwidth / 2);
    int y = (maxheight / 2);

    switch (state) {
      case 1:
        playing = true;
        DrawRectangle(
          0, 0,
          GetScreenWidth(), 
          GetScreenHeight(),
          GREEN             
        );

        DrawTexture(player_idle, x - (player_idle.width /2), y - (player_idle.height / 2), WHITE);

        break;

      case 2:
        break;

      case 3:
        x -= (credits.width / 2); 
        y -= ((credits.height / 2) + 20);

        DrawTexture(credits_title, (maxwidth / 2) - (credits_title.width / 2), 20, WHITE);

        DrawTexturePro(
          credits,
          (Rectangle){ 0, 0, credits.width, credits.height}, (Rectangle){ x, y, credits.width, credits.height}, 
          (Vector2){ 0, 0 },  
          0.0f,              
          WHITE             
        );

        x = (maxwidth / 2) - (buttons[4].width / 2);
        y = maxheight - 100;

        Rectangle bounds = { x, y, buttons[4].width, buttons[4].height };
        bool hovered = CheckCollisionPointRec(GetMousePosition(), bounds);
        bool clicked = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        if (hovered) {
          DrawTexturePro(
            buttons[4],
            (Rectangle){ 0, 0, buttons[4].width, buttons[4].height}, 
            (Rectangle){ x - 8, y - 8, buttons[4].width + 16, buttons[4].height + 16}, 
            (Vector2){ 0, 0 },  
            0.0f,              
            (Color){ 0, 255, 255, 255 }
            );
          if (clicked) state = 0;
        } else {
          DrawTexture(buttons[4], x, y, WHITE);
        }
        break;

      case 4: run = false; break;

      default:
        break;
    }

    EndDrawing();
  }

  UnloadTexture(player_idle);
  UnloadTexture(credits_title);
  UnloadTexture(credits);
  for (int i = 0; i < 5; i++) UnloadTexture(buttons[i]);
  UnloadTexture(title);
  UnloadTexture(menu_bg);
  CloseWindow();
  return 0;
}
