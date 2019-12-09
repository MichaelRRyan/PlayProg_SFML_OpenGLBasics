#include <Game.h>

Game::Game() :
	window(VideoMode(800, 600), "OpenGL"),
	m_currentShape{ ShapeName::Triangle }
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
					case ShapeName::Triangle:
						m_currentShape = ShapeName::Point;
						break;
					case ShapeName::Point:
						m_currentShape = ShapeName::Triangle;
						break;
					default:
						m_currentShape = ShapeName::Triangle;
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

	if (m_currentShape == ShapeName::Triangle)
	{
		glBegin(GL_TRIANGLES);
		{
			glVertex3f(0.0, 1.0, -5.0);
			glVertex3f(-1.0, -1.0, -5.0);
			glVertex3f(1.0, -1.0, -5.0);
		}
		glEnd();
	}
	else if (m_currentShape == ShapeName::Point)
	{
		glBegin(GL_POINTS);
		{
			glVertex3f(0.0, 1.0, -5.0);
			glVertex3f(-1.0, -1.0, -5.0);
			glVertex3f(1.0, -1.0, -5.0);
		}
		glEnd();
	}

	window.display();
}

void Game::unload()
{
	//cout << "Cleaning up" << endl;
}

