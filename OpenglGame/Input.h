#ifndef INPUT_H
#define INPUT_H

// Input handling functions
void keyboardDown(unsigned char key, int x, int y);
void handleMenuInput(unsigned char key);
void handleMenuSelection();
void handlePlayingInput(unsigned char key);
void update(int value);
void keyboardUp(unsigned char key, int x, int y);
void specialKeyDown(int key, int x, int y);
void specialKeyUp(int key, int x, int y);

#endif