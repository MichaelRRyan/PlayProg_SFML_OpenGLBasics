#include <Game.h>

Game::Game() :
	window(VideoMode(800, 600), "OpenGL"),
	m_currentShape{ ShapeName::Point }
{
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		//cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					switch (m_currentShape)
					{
					case ShapeName::Point:
						m_currentShape = ShapeName::Lines;
						break;
					case ShapeName::Lines:
						m_currentShape = ShapeName::LineStrip;
						break;
					case ShapeName::LineStrip:
						m_currentShape = ShapeName::LineLoop;
						break;
					case ShapeName::LineLoop:
						m_currentShape = ShapeName::Triangles;
						break;
					case ShapeName::Triangles:
						m_currentShape = ShapeName::TriangleStrip;
						break;
					case ShapeName::TriangleStrip:
						m_currentShape = ShapeName::TriangleFan;
						break;
					case ShapeName::TriangleFan:
						m_currentShape = ShapeName::Quads;
						break;
					case ShapeName::Quads:
						m_currentShape = ShapeName::QuadStrip;
						break;
					case ShapeName::QuadStrip:
						m_currentShape = ShapeName::Polygon;
						break;
					case ShapeName::Polygon:
						m_currentShape = ShapeName::Point;
						break;
					}
				}
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	//cout << "Update up" << endl;
}

void Game::draw()
{
	//cout << "Draw up" << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	switch (m_currentShape)
	{
	case ShapeName::Point:
		glBegin(GL_POINTS);
		{
			glVertex3f(0.0, 1.0, -5.0);
			glVertex3f(-1.0, -1.0, -5.0);
			glVertex3f(1.0, -1.0, -5.0);
			glVertex3f(2.0, 1.0, -5.0);
		}
		glEnd();
		break;
	case ShapeName::Lines:
		glBegin(GL_LINES);
		{
			glVertex3f(0.0, 1.0, -5.0);
			glVertex3f(-1.0, -1.0, -5.0);
			glVertex3f(1.0, -1.0, -5.0);
			glVertex3f(2.0, 1.0, -5.0);
		}
		glEnd();
		break;
	case ShapeName::LineStrip:
		glBegin(GL_LINE_STRIP);
		{
			glVertex3f(0.0, 1.0, -5.0);
			glVertex3f(-1.0, -1.0, -5.0);
			glVertex3f(1.0, -1.0, -5.0);
			glVertex3f(2.0, 1.0, -5.0);
		}
		glEnd();
		break;
	case ShapeName::LineLoop:
		glBegin(GL_LINE_LOOP);
		{
			glVertex3f(0.0, 1.0, -5.0);
			glVertex3f(-1.0, -1.0, -5.0);
			glVertex3f(1.0, -1.0, -5.0);
			glVertex3f(2.0, 1.0, -5.0);
		}
		glEnd();
		break;
	case ShapeName::Triangles:
		glBegin(GL_TRIANGLES);
		{
			glVertex3f(0.0, 1.0, -5.0);
			glVertex3f(-1.0, -1.0, -5.0);
			glVertex3f(1.0, -1.0, -5.0);
		}
		glEnd();
		break;
	case ShapeName::TriangleStrip:
		glBegin(GL_TRIANGLE_STRIP);
		{
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(-1.0, 2.0, -5.0);
			glVertex3f(-2.0, 0.0, -5.0);
			glVertex3f(0.0, 0.0, -5.0);

			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(-1.0,-2.0, -5.0);

			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(1.0, -2.0, -5.0);
		}
		glEnd();
		break;
	case ShapeName::TriangleFan:
		glBegin(GL_TRIANGLE_FAN);
		{
			glColor3f(1.0f, 1.0f, 1.0f);
			glVertex3f(0.0, -1.0, -5.0);
			glVertex3f(-1.0, 1.0, -5.0);
			glVertex3f(1.0, 1.0, -5.0);

			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(2.0, -1.0, -5.0);

			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(0.0, -2.0, -5.0);
			
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(-1.0, -1.0, -5.0);
		}
		glEnd();
		break;
	case ShapeName::Quads:
		glBegin(GL_QUADS);
		{
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(0.0, -1.0, -5.0);

			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(-1.0, 1.0, -5.0);

			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(1.0, 1.0, -5.0);

			glColor3f(1.0f, 1.0f, 0.0f);
			glVertex3f(2.0, -1.0, -5.0);
		}
		glEnd();
		break;
	case ShapeName::QuadStrip:
		glBegin(GL_QUAD_STRIP);
		{
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(-0.5, 1.0, -5.0);

			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(0.5, 1.0, -5.0);

			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(-0.5, 0.0, -5.0);

			glColor3f(1.0f, 1.0f, 0.0f);
			glVertex3f(0.5, 0.0, -5.0);

			glColor3f(1.0f, 1.0f, 1.0f);
			glVertex3f(-1.0, -1.0, -5.0);

			glColor3f(1.0f, 1.0f, 1.0f);
			glVertex3f(0.0, -1.5, -5.0);
		}
		glEnd();
		break;
	case ShapeName::Polygon:
		glBegin(GL_POLYGON);
		{
			glVertex3f(0.0, 1.0, -5.0);
			glVertex3f(-1.0, -1.0, -5.0);
			glVertex3f(1.0, -1.0, -5.0);
		}
		glEnd();
		break;
	}

	window.display();
}

void Game::unload()
{
	//cout << "Cleaning up" << endl;
}

