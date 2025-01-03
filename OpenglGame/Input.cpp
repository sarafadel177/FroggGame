#define _CRT_SECURE_NO_WARNINGS
#include "Input.h"
#include "Globals.h"
#include "Game.h"
#include <GL/glut.h>


void keyboardDown(unsigned char key, int x, int y) {
    keys[key] = true;

    switch (currentState) {
    case MENU:
        handleMenuInput(key);
        break;
    case PLAYING:
        handlePlayingInput(key);
        break;
    case HIGH_SCORES:
    case GAME_OVER:
        if (key == 27 || key == 13) { // ESC or Enter
            currentState = MENU;
        }
        break;
    }

    glutPostRedisplay();
}

void handleMenuInput(unsigned char key) {
    switch (key) {
    case 13: // Enter
        handleMenuSelection();
        break;
    case 'w':
    case 'W':
        menuSelection = (menuSelection - 1 + 4) % 4;
        break;
    case 's':
    case 'S':
        menuSelection = (menuSelection + 1) % 4;
        break;
    case 27: // ESC
        cleanup();
        exit(0);
        break;
    }
}
void handleMenuSelection() {
    switch (menuSelection) {
    case 0: // Start New Game
        resetGame();
        currentState = PLAYING;
        break;
    case 1: // Resume Game
        if (isGameInitialized && !gameOver) {
            currentState = PLAYING;
        }
        else {
            // If no game is in progress, start a new game
            resetGame();
            currentState = PLAYING;
        }
        break;
    case 2: // High Scores
        currentState = HIGH_SCORES;
        break;
    case 3: // Exit
        cleanup();
        exit(0);
        break;
    }
}

void handlePlayingInput(unsigned char key) {
    switch (key) {
    case 'w':
    case 'W':
        if (frogY + MOVE_SPEED <= WINDOW_HEIGHT - 50) {
            frogY += MOVE_SPEED;
            frogAngle = 0;
        }
        break;
    case 's':
    case 'S':
        if (frogY - MOVE_SPEED >= 50) {
            frogY -= MOVE_SPEED;
            frogAngle = 180;
        }
        break;
    case 'a':
    case 'A':
        if (frogX - MOVE_SPEED >= 20) {
            frogX -= MOVE_SPEED;
            frogAngle = 90;
        }
        break;
    case 'd':
    case 'D':
        if (frogX + MOVE_SPEED <= WINDOW_WIDTH - 20) {
            frogX += MOVE_SPEED;
            frogAngle = -90;
        }
        break;
    case 'p':
    case 'P':
    case 27: // ESC
        currentState = MENU;
        break;
    case 'r':
    case 'R':
        resetFrogPosition();
        break;
    }
}
void update(int value) {
    if (currentState == PLAYING) {
        updateGame();
    }
    glutPostRedisplay();
    glutTimerFunc(FRAME_DELAY, update, 0);
}

void keyboardUp(unsigned char key, int x, int y) {
    keys[key] = false;
}

void specialKeyDown(int key, int x, int y) {
    if (currentState == MENU) {
        // Menu navigation with arrow keys
        switch (key) {
        case GLUT_KEY_UP:
            menuSelection = (menuSelection - 1 + 4) % 4;
            break;
        case GLUT_KEY_DOWN:
            menuSelection = (menuSelection + 1) % 4;
            break;
        }
        glutPostRedisplay();
        return;
    }

    // Game movement with arrow keys
    switch (key) {
    case GLUT_KEY_UP:
        if (currentState == PLAYING && frogY + MOVE_SPEED <= WINDOW_HEIGHT - 50) {
            frogY += MOVE_SPEED;
            frogAngle = 0;
        }
        break;
    case GLUT_KEY_DOWN:
        if (currentState == PLAYING && frogY - MOVE_SPEED >= 50) {
            frogY -= MOVE_SPEED;
            frogAngle = 180;
        }
        break;
    case GLUT_KEY_LEFT:
        if (currentState == PLAYING && frogX - MOVE_SPEED >= 20) {
            frogX -= MOVE_SPEED;
            frogAngle = 90;
        }
        break;
    case GLUT_KEY_RIGHT:
        if (currentState == PLAYING && frogX + MOVE_SPEED <= WINDOW_WIDTH - 20) {
            frogX += MOVE_SPEED;
            frogAngle = -90;
        }
        break;
    }
    glutPostRedisplay();
}

void specialKeyUp(int key, int x, int y) {
    // This function can remain the same if you're not using key state tracking
    switch (key) {
    case GLUT_KEY_UP:
        keys[GLUT_KEY_UP] = false;
        break;
    case GLUT_KEY_DOWN:
        keys[GLUT_KEY_DOWN] = false;
        break;
    case GLUT_KEY_LEFT:
        keys[GLUT_KEY_LEFT] = false;
        break;
    case GLUT_KEY_RIGHT:
        keys[GLUT_KEY_RIGHT] = false;
        break;
    }
}


