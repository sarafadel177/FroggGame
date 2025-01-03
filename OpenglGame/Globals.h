#ifndef GLOBALS_H
#define GLOBALS_H

#include <vector>
#include "Game.h"

extern GameState currentState;
extern int currentLevel;
extern int score;
extern int lives;
extern int highScores[5];
extern float frogX;
extern float frogY;
extern float frogAngle;
extern bool keys[256];
extern const float MOVE_SPEED;
extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;
extern int crossingsCompleted;
extern std::vector<Obstacle> obstacles;
extern int menuSelection;
extern float carY[3];
extern float riverY[2];
extern bool isOnLog;
extern float currentLogSpeed;
extern bool gameOver;
extern bool isGameInitialized;
extern const int FRAME_DELAY;
extern const int MAX_LEVELS;
extern Level levels[5];

#endif