#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include "Globals.h"
#include "Game.h"
#include "Graphics.h"
#include "Input.h"
#include <GL/glut.h>

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Frogger");

    init();
    atexit(cleanup);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboardDown);
    glutKeyboardUpFunc(keyboardUp);
    glutSpecialFunc(specialKeyDown);
    glutSpecialUpFunc(specialKeyUp);
    glutTimerFunc(FRAME_DELAY, update, 0);

    glutMainLoop();
    return 0;
}