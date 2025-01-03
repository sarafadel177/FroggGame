#define _CRT_SECURE_NO_WARNINGS
#include "Game.h"
#include "Globals.h"
#include <fstream>
#include <algorithm>
#include <gl/GLU.h>
#include <gl/GL.h>
#include <cmath>
void saveHighScores() {
    std::ofstream file("highscores.txt");
    if (file.is_open()) {
        for (int i = 0; i < 5; i++) {
            file << highScores[i] << std::endl;
        }
        file.close();
    }
}

void loadHighScores() {
    std::ifstream file("highscores.txt");
    if (file.is_open()) {
        for (int i = 0; i < 5; i++) {
            file >> highScores[i];
        }
        file.close();
    }
}

void initLevel(int level) {
    if (level < 1 || level > MAX_LEVELS) return;

    obstacles.clear();
    Level& currentLevelData = levels[level - 1];

    // Cars
    for (int i = 0; i < currentLevelData.numObstacles; i++) {
        Obstacle obs;
        obs.x = static_cast<float>(rand() % WINDOW_WIDTH);
        obs.y = 150.0f + (i % 3) * 100.0f;
        obs.speed = currentLevelData.minSpeed +
            static_cast<float>(rand()) / RAND_MAX * (currentLevelData.maxSpeed - currentLevelData.minSpeed);
        obs.type = 0;
        obs.width = 80;
        obs.height = 40;
        obs.isActive = true;
        obstacles.push_back(obs);
    }

    // Logs
    for (int i = 0; i < 4; i++) {
        Obstacle log;
        log.x = static_cast<float>(rand() % WINDOW_WIDTH);
        log.y = riverY[i % 2];
        log.speed = (i % 2 == 0) ? 2.0f : -2.0f;
        log.type = 2;
        log.width = 120;
        log.height = 40;
        log.isActive = true;
        obstacles.push_back(log);
    }
}
void updateGame() {
    if (currentState != PLAYING || !isGameInitialized) return;

    // Keep frog within bounds
    frogX = (std::max)(20.0f, (std::min)(frogX, static_cast<float>(WINDOW_WIDTH - 20)));
    frogY = (std::max)(20.0f, (std::min)(frogY, static_cast<float>(WINDOW_HEIGHT - 20)));

    isOnLog = false;
    currentLogSpeed = 0.0f;

    for (auto& obs : obstacles) {
        obs.x += obs.speed;

        // Wrap around screen
        if (obs.x > WINDOW_WIDTH + obs.width / 2) {
            obs.x = -obs.width / 2;
        }
        else if (obs.x < -obs.width / 2) {
            obs.x = WINDOW_WIDTH + obs.width / 2;
        }

        // Collision detection
        if (frogX > obs.x - obs.width / 2 && frogX < obs.x + obs.width / 2 &&
            frogY > obs.y - obs.height / 2 && frogY < obs.y + obs.height / 2) {

            if (obs.type == 0) { // Car collision
                lives--;
                if (lives <= 0) {
                    handleGameOver();
                }
                else {
                    resetFrogPosition();
                }
            }
            else if (obs.type == 2) { // Log collision
                isOnLog = true;
                currentLogSpeed = obs.speed;
            }
        }
    }

    // Handle log riding and river collision
    if (isOnLog) {
        frogX += currentLogSpeed;
    }
    else if (isInRiver()) {
        handleDrowning();
    }

    // Handle successful crossing
    if (frogY >= WINDOW_HEIGHT - 50) {
        handleSuccessfulCrossing();
    }
}


void resetGame() {
    obstacles.clear();
    currentLevel = 1;
    score = 0;
    lives = 3;
    crossingsCompleted = 0;
    frogX = WINDOW_WIDTH / 2;
    frogY = 50;
    frogAngle = 0;
    gameOver = false;
    isOnLog = false;
    currentLogSpeed = 0.0f;
    isGameInitialized = true;
    initLevel(currentLevel);
}

bool isInRiver() {
    return (frogY >= riverY[0] - 20 && frogY <= riverY[0] + 20) ||
        (frogY >= riverY[1] - 20 && frogY <= riverY[1] + 20);
}

void handleDrowning() {
    lives--;
    if (lives <= 0) {
        handleGameOver();
    }
    else {
        resetFrogPosition();
    }
}
void handleGameOver() {
    currentState = GAME_OVER;
    updateHighScores();
    saveHighScores();
}
void handleSuccessfulCrossing() {
    crossingsCompleted++;
    score += 100 * currentLevel;

    if (crossingsCompleted >= levels[currentLevel - 1].requiredCrossings) {
        currentLevel++;
        crossingsCompleted = 0;

        if (currentLevel > MAX_LEVELS) {
            handleGameOver();
        }
        else {
            initLevel(currentLevel);
        }
    }

    resetFrogPosition();
}

void updateHighScores() {
    for (int i = 0; i < 5; i++) {
        if (score > highScores[i]) {
            for (int j = 4; j > i; j--) {
                highScores[j] = highScores[j - 1];
            }
            highScores[i] = score;
            break;
        }
    }
}

void resetFrogPosition() {
    frogX = WINDOW_WIDTH / 2;
    frogY = 50;
    frogAngle = 0;
}

void cleanup() {
    saveHighScores();
    obstacles.clear();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
    loadHighScores();
}