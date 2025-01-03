#define _CRT_SECURE_NO_WARNINGS
#include "Graphics.h"
#include "Globals.h"
#include <GL/glut.h>
#include <cmath>

void drawCircle(float cx, float cy, float r, int segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void drawCar(float x, float y) {
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(x - 40, y - 15);
    glVertex2f(x + 40, y - 15);
    glVertex2f(x + 40, y + 15);
    glVertex2f(x - 40, y + 15);
    glEnd();

    glColor3f(0.8f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(x - 20, y + 15);
    glVertex2f(x + 20, y + 15);
    glVertex2f(x + 15, y + 25);
    glVertex2f(x - 15, y + 25);
    glEnd();

    glColor3f(0.7f, 0.7f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(x - 15, y + 16);
    glVertex2f(x - 5, y + 16);
    glVertex2f(x - 7, y + 23);
    glVertex2f(x - 13, y + 23);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(x + 5, y + 16);
    glVertex2f(x + 15, y + 16);
    glVertex2f(x + 13, y + 23);
    glVertex2f(x + 7, y + 23);
    glEnd();

    glColor3f(0.2f, 0.2f, 0.2f);
    drawCircle(x - 25, y - 15, 8, 16);
    drawCircle(x + 25, y - 15, 8, 16);
}

void drawLog(float x, float y) {
    glColor3f(0.6f, 0.3f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(x - 60, y - 20);
    glVertex2f(x + 60, y - 20);
    glVertex2f(x + 60, y + 20);
    glVertex2f(x - 60, y + 20);
    glEnd();

    glColor3f(0.5f, 0.25f, 0.0f);
    for (float i = -50; i <= 50; i += 20) {
        glBegin(GL_LINES);
        glVertex2f(x + i, y - 20);
        glVertex2f(x + i, y + 20);
        glEnd();
    }
}

void drawBackground() {
    glColor3f(0.2f, 0.8f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(WINDOW_WIDTH, 0);
    glVertex2f(WINDOW_WIDTH, WINDOW_HEIGHT);
    glVertex2f(0, WINDOW_HEIGHT);
    glEnd();

    // Draw roads
    glColor3f(0.2f, 0.2f, 0.2f);
    for (int i = 0; i < 3; i++) {
        float y = carY[i] - 30;
        glBegin(GL_QUADS);
        glVertex2f(0, y);
        glVertex2f(WINDOW_WIDTH, y);
        glVertex2f(WINDOW_WIDTH, y + 60);
        glVertex2f(0, y + 60);
        glEnd();

        glColor3f(1.0f, 1.0f, 1.0f);
        for (float x = 0; x < WINDOW_WIDTH; x += 80) {
            glBegin(GL_QUADS);
            glVertex2f(x, y + 28);
            glVertex2f(x + 40, y + 28);
            glVertex2f(x + 40, y + 32);
            glVertex2f(x, y + 32);
            glEnd();
        }
        glColor3f(0.2f, 0.2f, 0.2f);
    }

    // Draw river
    glColor3f(0.0f, 0.3f, 0.8f);
    for (int i = 0; i < 2; i++) {
        float y = riverY[i] - 30;
        glBegin(GL_QUADS);
        glVertex2f(0, y);
        glVertex2f(WINDOW_WIDTH, y);
        glVertex2f(WINDOW_WIDTH, y + 60);
        glVertex2f(0, y + 60);
        glEnd();
    }

    // Draw river waves
    glColor3f(0.0f, 0.4f, 0.9f);
    for (float x = 0; x < WINDOW_WIDTH; x += 40) {
        glBegin(GL_TRIANGLES);
        glVertex2f(x, riverY[0] - 20);
        glVertex2f(x + 20, riverY[0] - 10);
        glVertex2f(x + 40, riverY[0] - 20);
        glEnd();
    }

    // Draw finish area
    glColor3f(0.0f, 0.0f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(0, WINDOW_HEIGHT - 50);
    glVertex2f(WINDOW_WIDTH, WINDOW_HEIGHT - 50);
    glVertex2f(WINDOW_WIDTH, WINDOW_HEIGHT);
    glVertex2f(0, WINDOW_HEIGHT);
    glEnd();
}

void drawHeart(float x, float y, float size) {
    // Draw the two upper circles
    glColor3f(1.0f, 0.0f, 0.0f);
    drawCircle(x - size * 0.3f, y + size * 0.3f, size * 0.3f, 32); // Left circle
    drawCircle(x + size * 0.3f, y + size * 0.3f, size * 0.3f, 32); // Right circle

    // Draw the lower triangle
    glBegin(GL_TRIANGLES);
    glVertex2f(x - size * 0.6f, y + size * 0.3f); // Left point
    glVertex2f(x + size * 0.6f, y + size * 0.3f); // Right point
    glVertex2f(x, y - size * 0.6f);              // Bottom point
    glEnd();
}

void drawFrog() {
    float size = 20.0f;

    glPushMatrix();
    glTranslatef(frogX, frogY, 0.0f);
    glRotatef(frogAngle, 0.0f, 0.0f, 1.0f);

    glColor3f(0.0f, 0.6f, 0.0f);
    drawCircle(0, 0, size, 32);

    glColor3f(0.0f, 0.8f, 0.0f);
    drawCircle(0, size * 0.5f, size * 0.6f, 32);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(size * 0.3f, size * 0.7f, size * 0.2f, 16);
    drawCircle(-size * 0.3f, size * 0.7f, size * 0.2f, 16);

    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(size * 0.3f, size * 0.7f, size * 0.1f, 16);
    drawCircle(-size * 0.3f, size * 0.7f, size * 0.1f, 16);

    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-size * 0.8f, 0);
    glVertex2f(-size * 1.2f, size * 0.4f);
    glVertex2f(-size * 0.4f, size * 0.4f);
    glVertex2f(size * 0.8f, 0);
    glVertex2f(size * 1.2f, size * 0.4f);
    glVertex2f(size * 0.4f, size * 0.4f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-size * 0.8f, -size * 0.2f);
    glVertex2f(-size * 1.2f, -size * 0.6f);
    glVertex2f(-size * 0.4f, -size * 0.6f);
    glVertex2f(size * 0.8f, -size * 0.2f);
    glVertex2f(size * 1.2f, -size * 0.6f);
    glVertex2f(size * 0.4f, -size * 0.6f);
    glEnd();

    glPopMatrix();
}
void drawMenu() {
    glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 1.0f, 0.0f);
    const char* title = "FROGGER";
    int titleWidth = 0;
    for (const char* c = title; *c != '\0'; c++) {
        titleWidth += glutBitmapWidth(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
    glRasterPos2f((WINDOW_WIDTH - titleWidth) / 2, WINDOW_HEIGHT - 100);
    for (const char* c = title; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }

    const char* menuItems[] = {
        "Start New Game",
        "Resume Game",
        "High Scores",
        "Exit"
    };
    const int numItems = 4;
    int menuStartY = WINDOW_HEIGHT - 200;
    int menuSpacing = 50;

    for (int i = 0; i < numItems; i++) {
        int itemWidth = 0;
        for (const char* c = menuItems[i]; *c != '\0'; c++) {
            itemWidth += glutBitmapWidth(GLUT_BITMAP_HELVETICA_18, *c);
        }

        float xPos = (WINDOW_WIDTH - itemWidth) / 2;
        float yPos = menuStartY - (i * menuSpacing);

        if (i == menuSelection) {
            glColor3f(0.2f, 0.6f, 0.2f);
            glBegin(GL_QUADS);
            glVertex2f(xPos - 20, yPos - 10);
            glVertex2f(xPos + itemWidth + 20, yPos - 10);
            glVertex2f(xPos + itemWidth + 20, yPos + 20);
            glVertex2f(xPos - 20, yPos + 20);
            glEnd();
            glColor3f(1.0f, 1.0f, 1.0f);
        }
        else {
            glColor3f(0.7f, 0.7f, 0.7f);
        }
        glRasterPos2f(xPos, yPos);
        for (const char* c = menuItems[i]; *c != '\0'; c++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
        }
    }

    glColor3f(0.5f, 0.5f, 0.5f);
    const char* instructions = "Use W/S keys to navigate, Enter to select";
    int instrWidth = 0;
    for (const char* c = instructions; *c != '\0'; c++) {
        instrWidth += glutBitmapWidth(GLUT_BITMAP_HELVETICA_12, *c);
    }
    glRasterPos2f((WINDOW_WIDTH - instrWidth) / 2, 50.0f);
    for (const char* c = instructions; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }
}

void drawHighScores() {
    glColor3f(1.0f, 1.0f, 1.0f);

    glRasterPos2f(350.0f, 500.0f);
    const char* title = "High Scores";
    for (const char* c = title; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    char scoreText[32];
    for (int i = 0; i < 5; i++) {
        sprintf(scoreText, "%d. %d", i + 1, highScores[i]);
        glRasterPos2f(350.0f, 400.0f - i * 40.0f);
        for (const char* c = scoreText; *c != '\0'; c++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
        }
    }

    glRasterPos2f(350.0f, 100.0f);
    const char* returnText = "Press ESC to return to menu";
    for (const char* c = returnText; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void drawHUD() {
    char text[32];
    glColor3f(1.0f, 1.0f, 1.0f);

    sprintf(text, "Score: %d", score);
    glRasterPos2f(10.0f, WINDOW_HEIGHT - 20.0f);
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    sprintf(text, "Level: %d", currentLevel);
    glRasterPos2f(10.0f, WINDOW_HEIGHT - 60.0f);
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    sprintf(text, "Crossings: %d/%d", crossingsCompleted, levels[currentLevel - 1].requiredCrossings);
    glRasterPos2f(10.0f, WINDOW_HEIGHT - 80.0f);
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    // Draw lives as hearts
    float startX = 20.0f;
    float startY = WINDOW_HEIGHT - 35.0f;
    float heartSize = 15.0f;
    for (int i = 0; i < lives; i++) {
        drawHeart(startX + i * (heartSize * 1.5f), startY, heartSize);
    }
}


void drawObstacle(const Obstacle& obs) {
    if (obs.type == 0) {
        drawCar(obs.x, obs.y);
    }
    else if (obs.type == 2) {
        drawLog(obs.x, obs.y);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    switch (currentState) {
    case MENU:
        drawMenu();
        break;

    case PLAYING:
        drawBackground();
        for (const auto& obs : obstacles) {
            drawObstacle(obs);
        }
        drawFrog();
        drawHUD();
        break;

    case HIGH_SCORES:
        drawHighScores();
        break;

    case GAME_OVER:
    {
        // Dark background
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw "GAME OVER" with largest font
        const char* gameOverText = "GAME OVER";
        int textWidth = glutBitmapLength(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)gameOverText);
        float centerX = (WINDOW_WIDTH - textWidth) / 2;
        float centerY = WINDOW_HEIGHT / 2 + 50;  // Moved up slightly

        glColor3f(1.0f, 0.0f, 0.0f);  // Red color
        glRasterPos2f(centerX, centerY);
        for (const char* c = gameOverText; *c != '\0'; c++) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
        }

        // Draw score with medium font
        char scoreText[32];
        sprintf(scoreText, "FINAL SCORE: %d", score);
        textWidth = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)scoreText);
        centerX = (WINDOW_WIDTH - textWidth) / 2;

        glColor3f(1.0f, 1.0f, 0.0f);  // Yellow color
        glRasterPos2f(centerX, centerY - 60);
        for (const char* c = scoreText; *c != '\0'; c++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
        }

        // Draw continue text with medium font
        const char* escText = "PRESS ESC TO CONTINUE";
        textWidth = glutBitmapLength(GLUT_BITMAP_HELVETICA_18, (const unsigned char*)escText);
        centerX = (WINDOW_WIDTH - textWidth) / 2;

        glColor3f(0.7f, 0.7f, 0.7f);  // Gray color
        glRasterPos2f(centerX, centerY - 120);
        for (const char* c = escText; *c != '\0'; c++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
        }
    }
    break;
    }

    glutSwapBuffers();
}