#ifndef Player_H
#define Player_H


extern struct Vector2 playerposition;
extern struct Vector2 playerdirection;
void player(void);
void draw_player(void);
void rotate(float rotatespeed);

#endif