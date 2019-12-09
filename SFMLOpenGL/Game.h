#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

using namespace std;
using namespace sf;

const std::string NAMES[]
{
	"Points",
	"Lines",
	"LineStrip",
	"LineLoop",
	"Triangles",
	"TriangleStrip",
	"TriangleFan",
	"Quads",
	"QuadStrip",
	"Polygon",
	"Model"
};

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	void processEvents();
	void initialize();
	void loadModel();
	void update();
	void draw();
	void unload();

	Window window;
	bool isRunning = false;

	const int primatives;

	GLuint index;

	float rotationAngle = 0.0f;
	float m_scale = 1.000f;
};