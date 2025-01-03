#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <Windows.h>
#include <GL/glut.h>
#include "Game.h"

// Drawing functions
void drawCircle(float cx, float cy, float r, int segments);
void drawCar(float x, float y);
void drawLog(float x, float y);
void drawBackground();
void drawFrog();
void drawMenu();
void drawHighScores();
void drawHUD();
void drawHeart(float x, float y, float size);
void drawObstacle(const Obstacle& obs);
void display();

#endif