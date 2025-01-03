# Frogger Game with Menu

## 🐸 Introduction

This is a *Frogger-inspired game* . The player controls a frog that must navigate through obstacles to reach the other side safely. The game includes:

- A *main menu* to start or exit the game.
- Intuitive *WASD controls* for movement.
- Challenging gameplay inspired by the classic Frogger.

## 🎮 Features

- *Interactive Menu*: Easily start the game or exit through the main menu.
- *Simple Controls*: Move your character using the W, A, S, and D keys.
- *Classic Gameplay*: Dodge obstacles, time your moves, and aim to reach the goal!

## 🕹️ How to Play

1. *Start the Game*: Use the menu to start the game.
2. *Move the Frog*:
   - *W*: Move up.
   - *A*: Move left.
   - *S*: Move down.
   - *D*: Move right.
   - or with the arrows
3. *Goal*: Safely guide the frog to the other side while avoiding obstacles.
## 🚀 Installation

Follow these steps to set up the environment and run the Frogger game:

## Prerequisites
1. *Operating System*: Windows 10/11 (64-bit).
2. *Development Tools*:
   - Microsoft Visual Studio Community 2019 or newer.
   - A graphics card supporting OpenGL 4.3 or later (lower versions might still work with adjustments).
3. *Libraries*:
   - FreeGLUT
   - GLEW
   - GLM

## Steps to Install

1. *Download Visual Studio*:
   - Download Microsoft Visual Studio Community Edition from [Visual Studio Downloads](https://my.visualstudio.com/Downloads).
   - Install it with the "Desktop development with C++" workload.

2. *Set Up Helper Libraries*:
   - Create a folder named OpenGLwrappers in the C: drive: C:\OpenGLwrappers.
   - Download and extract the following libraries into C:\OpenGLwrappers:
     - *FreeGLUT*: [Download FreeGLUT](http://files.transmissionzero.co.uk/software/development/GLUT/older/freeglut-MSVC-2.8.1-1.mp.zip)
     - *GLEW*: [Download GLEW](https://sourceforge.net/projects/glew/files/glew/1.10.0/glew-1.10.0-win32.zip/download)
     - *GLM*: [Download GLM](https://github.com/g-truc/glm/releases/download/0.9.7.5/glm-0.9.7.5.zip)

3. *Configure Windows Environment*:
   - Copy freeglut.dll from C:\OpenGLwrappers\freeglut-MSVC-2.8.1-1.mp\freeglut\bin to C:\Windows\SysWOW64.
   - Copy glew32.dll from C:\OpenGLwrappers\glew-1.10.0-win32\glew-1.10.0\bin\Release\Win32 to C:\Windows\SysWOW64.
   - Ensure glu32.dll exists in C:\Windows\SysWOW64. If missing, search online for resources to add it.

4. *Set Up Visual Studio Project*:
   - Configure the project to include library paths:
     - Add the following include directories:
       
       C:\OpenGLwrappers\freeglut-MSVC-2.8.1-1.mp\freeglut\include
       C:\OpenGLwrappers\glew-1.10.0-win32\glew-1.10.0\include
       C:\OpenGLwrappers\glm-0.9.7.5\glm
       
     - Add the following library directories:
       
       C:\OpenGLwrappers\freeglut-MSVC-2.8.1-1.mp\freeglut\lib
       C:\OpenGLwrappers\glew-1.10.0-win32\glew-1.10.0\lib\Release\Win32
       
     - Add the following additional dependencies:
       
       glew32.lib
       opengl32.lib
       

5. *Build and Run*:
   - Open the project in Visual Studio, build it, and run the executable to play the Frogger game.
