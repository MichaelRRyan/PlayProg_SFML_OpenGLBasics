#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <typeinfo>

using namespace std;
using namespace sf;

enum class ShapeName
{
	Point,
	Lines,
	LineStrip,
	LineLoop,
	Triangles,
	TriangleStrip,
	TriangleFan,
	Quads,
	QuadStrip,
	Polygon
};

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();

	ShapeName m_currentShape;

	// // Uncomment for Part 2
	// // ********************
	// const int primatives;

	//GLuint index;
	//Clock clock;
	//Time elapsed;

	//float rotationAngle = 0.0f;
	// // ********************
};