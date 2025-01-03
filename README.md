
## 🚀 Installation

To run this game on your system, follow the steps below:

### Prerequisites

Ensure the following tools are installed on your system:

1. *C++ Compiler*: A compiler like g++ (part of GCC) or MSVC (Microsoft Visual C++).
2. *OpenGL Libraries*: The OpenGL development libraries must be installed.
3. *GLFW* and *GLAD*: If not included in the template, ensure these are installed for managing OpenGL contexts and loading OpenGL functions.
4. *Visual Studio Code*: The game is written using a VS Code OpenGL template.

---

### Steps

1. *Clone the Repository*  
   Clone this repository to your local machine:
   bash
   git clone https://github.com/sarafadel177/FroggGame
   cd FroggGame
   

2. *Set Up OpenGL Environment*  
   Depending on your operating system:

   #### *Windows*
   - Install *MinGW* or *MSVC* for compiling C++ code.
   - Download and configure the necessary OpenGL libraries (GLFW, GLAD, GLU, etc.).
   - Ensure all library files (e.g., glfw3.lib, opengl32.lib) are linked in your build process.

   #### *Linux*
   - Install OpenGL and GLFW:
     bash
     sudo apt update
     sudo apt install build-essential libglfw3-dev libgl1-mesa-dev
     

   #### *MacOS*
   - Install dependencies using Homebrew:
     bash
     brew install glfw
     

3. *Build the Project*  
   Open the project folder in Visual Studio Code and ensure the VS Code OpenGL template is correctly configured.

   If you're using a *Makefile*:
   bash
   make
   

   Or compile manually with:
   bash
   g++ -o frogger main.cpp -lGL -lGLU -lglfw
   

4. *Run the Game*  
   After successful compilation, run the executable:
   bash
   ./frogger
   
