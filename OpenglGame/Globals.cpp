#include "Globals.h"

// Define all global variables
GameState currentState = MENU;
int currentLevel = 1;
int score = 0;
int lives = 3;
int highScores[5] = { 0 };
float frogX = 400.0f;
float frogY = 50.0f;
float frogAngle = 0.0f;
bool keys[256] = { false };
const float MOVE_SPEED = 50.0f;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
int crossingsCompleted = 0;
std::vector<Obstacle> obstacles;
int menuSelection = 0;
float carY[3] = { 150.0f, 250.0f, 350.0f };
float riverY[2] = { 400.0f, 500.0f };
bool isOnLog = false;
float currentLogSpeed = 0.0f;
bool gameOver = false;
bool isGameInitialized = false;
const int FRAME_DELAY = 16;
const int MAX_LEVELS = 5;

Level levels[MAX_LEVELS] = {
    {5, 3.0f, 5.0f, 1},
    {7, 4.0f, 6.0f, 2},
    {9, 5.0f, 7.0f, 3},
    {11, 6.0f, 8.0f, 4},
    {13, 7.0f, 9.0f, 5}
};