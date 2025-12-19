**🌧️ Rain & Flood Simulation in OpenGL (2D)**
A 2D graphical simulation built using C++ and OpenGL (GLUT) that demonstrates a dynamic rain system causing a gradually rising flood. The flood slowly submerges a house and trees under a dark, stormy environment.

**🌟 Features**

* **Dynamic Rain System***

* Particle-based system with up to 1000 randomized raindrops

* Continuous falling rain across the entire screen

***Rising Flood Mechanic***

* Water level rises in real time as raindrops hit the surface

* Gradually submerges the house and trees

***Custom Geometric Objects***

* **House**: Multi-colored structure with roof, windows, and door

* **Tree:**

* **Roots**: obj6, obj7

* **Leaves**: obj8, obj9

* **Sun:** Circular yellow polygon (obj10) positioned in the sky

***Transparency Effects***

* Semi-transparent water using OpenGL alpha blending for realism

**🛠️ Built With**

* C++

* OpenGL / GLUT – Rendering and animation loop

* Windows API – Window management and compatibility

**🚀 How It Works**

***📐 Coordinate System***

The simulation uses a 2D orthographic projection:

gluOrtho2D(-18, 18, -15, 15);

* Center of the screen is (0, 0)

* Left to right: -18 to 18

* Bottom to top: -15 to 15

**⚙️ Core Functions**

***addDrop()***

* Randomizes raindrop X-coordinate between -18 and 18

* Ensures full-screen rain coverage

***update()***

* Moves raindrops downward

* Detects collision with water level

* Increases waterLevel dynamically

***drawWater()***

* Draws a quad from:

* Bottom of screen: y = -15

* Top of water: y = waterLevel

* Uses transparency for flood effect

***display()***

Renders objects in correct layering order:

1.Sun

2.Trees

3.House

4.Water

5.Rain

This ensures realistic visual depth.

**🔧 Installation & Setup**

🖥️ Environment

* ***Any C++ IDE such as:***

* Code::Blocks

* Visual Studio

**📁 Files**

* Include main.cpp in your project

🔗 Required Libraries

**Link against:**

* freeglut

* opengl32

* glu32

**▶️ Run**

* Compile the project

* Execute the program to view the simulation

**📜 License**

This project is for educational purposes.
Feel free to modify and improve it.

**👤 Author**

**A.S.M. Sium**

Creative Web Developer 💻 | Photographer 📸

🌐 Passionate about visual storytelling and interactive graphics

**📸 Preview**

<img width="1044" height="784" alt="Screenshot 2025-12-20 012833" src="https://github.com/user-attachments/assets/5e82e4df-669b-41bf-b8ca-376f24f1aff9" />
