#include <stdio.h>
#include "raylib.h"
#include "map.h"
#include "player.h"
 int main(){
   SetConfigFlags(FLAG_WINDOW_HIGHDPI );
   SetTargetFPS(60);
   InitWindow(900,900,"عرفان توحیدی ");
   init_world_map();
   while (!WindowShouldClose())
   {
      player();
      update_map();
      BeginDrawing();
      ClearBackground(RAYWHITE);
      draw_world_map();
      draw_player();
      EndDrawing();
      
   }
   CloseWindow();
    return 0;
 }