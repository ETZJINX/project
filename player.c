#include "player.h"
#include "raylib.h"
#include "raymath.h"
#include "map.h"
Vector2 playerposition = {450,300};
Vector2 playerdirection = {1,0};
Vector2 plane = {0, 0.66f};
float speed = 400;
float rotatSpeed = 0.1f ;
void rotate(float rotatespeed){
    float olddirection = playerdirection.x;
    playerdirection.x = playerdirection.x *cosf(rotatespeed ) - playerdirection.y * sinf(rotatespeed);
    playerdirection.y = olddirection * sinf(rotatespeed ) + playerdirection.y * cosf(rotatespeed );

    float oldplanex = plane.x;
    plane.x = plane.x * cosf(rotatespeed ) - plane.y * sinf(rotatespeed);
    plane.y = oldplanex * sinf(rotatespeed ) + plane.y * cosf(rotatespeed );

}
void player(void){
    Vector2 newposition = playerposition;
    

    if (IsKeyDown(KEY_W))
    {
        newposition.y -= speed * GetFrameTime();
        int i = newposition.x / 30;
        int j = newposition.y / 30;
        if (world_map[i][j] == 1)
        {
            playerposition.x = newposition.x;
            newposition.y = playerposition.y;
        }
        else playerposition = newposition;
    }
    if (IsKeyDown(KEY_S))
    {
        newposition.y += speed * GetFrameTime();
        int i = newposition.x / 30;
        int j = newposition.y / 30;
        if (world_map[i][j] == 1)
        {
            playerposition.x = newposition.x;
            newposition.y = playerposition.y;
        }
        else playerposition = newposition;
    }
    if (IsKeyDown(KEY_A))
    {
        newposition.x -= speed * GetFrameTime();
        int i = newposition.x / 30;
        int j = newposition.y / 30;
        if (world_map[i][j] == 1)
        {
            playerposition.y = newposition.y;
            newposition.x = playerposition.x;
        }
        else playerposition = newposition;
    }
    if (IsKeyDown(KEY_D))
    {        
        newposition.x += speed * GetFrameTime();
        int i = newposition.x / 30;
        int j = newposition.y / 30;
        if (world_map[i][j] == 1)
        {
            playerposition.y = newposition.y;
            newposition.x = playerposition.x;
        }
        else playerposition = newposition;
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        rotate(rotatSpeed);
    }
    if (IsKeyDown(KEY_LEFT))
    {
        rotate(-rotatSpeed);
    }
    
}



void draw_player(void){
    DrawCircleV(playerposition,10, RED);
    Vector2 lineEnd = Vector2Add(
    playerposition,
    Vector2Scale(playerdirection, 20)
);
    DrawLineEx(playerposition, lineEnd, 5, RED);
}

