#include "raylib.h"
#include "time.h"
#include "stdlib.h"

int main() {
  const int WIDTH = 1024;
  const int HEIGHT = 576;
  bool run = true;
  bool playing = false;
  int state = 0;
  int printed_crytal = 0;

  // seed for rand()
  srand(time(NULL));

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
  Texture2D blue_crystal = LoadTexture("assets/textures/collectables/crystal_blue.png");
  Texture2D gold_crystal = LoadTexture("assets/textures/collectables/crystal_gold.png");
  Texture2D purple_crystal = LoadTexture("assets/textures/collectables/crystal_purple.png");

  int crystal_X[10];
  int crystal_Y[10];

  for (int i = 0; i < 10; i++) {
    crystal_X[i] = rand() % GetScreenWidth() - player_idle.width;
    crystal_Y[i] = rand() % GetScreenHeight() - player_idle.height;
  }


    int x = (GetScreenWidth() / 2) - (player_idle.width / 2);
    int y = (GetScreenHeight() / 2) - (player_idle.height / 2);

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

    switch (state) {
      case 1:
        playing = true;

        if (IsKeyDown(KEY_W)) y -= 5; 
        if (IsKeyDown(KEY_A)) x -= 5; 
        if (IsKeyDown(KEY_S)) y += 5; 
        if (IsKeyDown(KEY_D)) x += 5; 
        if (IsKeyDown(KEY_UP)) y -= 5; 
        if (IsKeyDown(KEY_LEFT)) x -= 5; 
        if (IsKeyDown(KEY_DOWN)) y += 5; 
        if (IsKeyDown(KEY_RIGHT)) x += 5; 

        if (y < 0) y = 0;
        if (y > GetScreenHeight() - 30) y = (GetScreenHeight() - 30);
        if (x < 0) x = 0;
        if (x > GetScreenWidth() - 20) x = (GetScreenWidth() - 20);

        DrawRectangle(
          0, 0,
          GetScreenWidth(), 
          GetScreenHeight(),
          GREEN             
        );

        DrawTexture(player_idle, x, y, WHITE);
        for (int i = 0; i < 6; i++) {
          DrawTexture(blue_crystal, crystal_X[i], crystal_Y[i], WHITE);
        }
        for (int i = 6; i < 8; i++) {
          DrawTexture(gold_crystal, crystal_X[i], crystal_Y[i], WHITE);
        }
        for (int i = 8; i < 10; i++) {
          DrawTexture(purple_crystal, crystal_X[i], crystal_Y[i], WHITE);
        }

        break;

      case 2:
        break;

      case 3:
        x = (GetScreenWidth() / 2) - (credits.width / 2);
        y = (GetScreenHeight() / 2) - ((credits.height / 2) + 20);

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

  UnloadTexture(purple_crystal);
  UnloadTexture(gold_crystal);
  UnloadTexture(blue_crystal);
  UnloadTexture(player_walk);
  UnloadTexture(player_idle);
  UnloadTexture(credits_title);
  UnloadTexture(credits);
  for (int i = 0; i < 5; i++) UnloadTexture(buttons[i]);
  UnloadTexture(title);
  UnloadTexture(menu_bg);
  CloseWindow();
  return 0;
}
