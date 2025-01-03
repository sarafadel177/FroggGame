#ifndef GAME_H
#define GAME_H
#include <Windows.h>
#include <vector>

enum GameState {
    MENU,
    PLAYING,
    GAME_OVER,
    HIGH_SCORES
};

struct Obstacle {
    float x, y;
    float speed;
    float width;
    float height;
    int type;
    bool isActive;
};

struct Level {
    int numObstacles;
    float minSpeed;
    float maxSpeed;
    int requiredCrossings;
};

// Game logic functions
void initLevel(int level);
void updateGame();
void resetGame();
bool isInRiver();
void handleDrowning();
void handleGameOver();
void handleSuccessfulCrossing();
void updateHighScores();
void resetFrogPosition();
void saveHighScores();
void loadHighScores();
void cleanup();
void init();

#endif