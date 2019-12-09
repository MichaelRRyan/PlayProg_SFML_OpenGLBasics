#include <Game.h>

 // Uncomment for Part 2
 // ********************
bool flip = false;
int current = 1;
 // ********************

Game::Game() :
	window(VideoMode(800, 600), "OpenGL"),
	primatives(11)
{
	 index = glGenLists(primatives);
}

Game::~Game() {}

void Game::run()
{
	initialize();

	sf::Clock gameClock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	float const FPS = 60.0f;
	sf::Time timePerFrame = sf::seconds( 1.0f / FPS );

	while (isRunning)
	{
		processEvents(); // Run as many times as possible
		timeSinceLastUpdate += gameClock.restart();

		// Update the game ever 60th of a second
		if (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // Run at least 60 frames per second
			update(); // Try run at 60 frames per second
		}
		draw(); // Run as many times as possible
	}
}

void Game::processEvents()
{
	Event event;

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
				current++;
				if (current > primatives)
				{
					current = 1;
				}

				cout << "Switched to Primative " << current << " \"" << NAMES[current - index] << "\"" << endl;
				glLoadIdentity();
				glTranslatef(0.0f, 0.0f, -5);
			}
		}
	}
}

void Game::initialize()
{
	isRunning = true;

	// Uncomment for Part 2
	// ********************
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(0.0f, 0.0f, -5);


	glNewList(index, GL_COMPILE);
	glBegin(GL_POINTS);
	{
		glVertex3f(0.0, 1.0, 0.0);
		glVertex3f(-1.0, -1.0, 0.0);
		glVertex3f(1.0, -1.0, 0.0);
		glVertex3f(2.0, 1.0, 0.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 1, GL_COMPILE);
	glBegin(GL_LINES);
	{
		glVertex3f(0.0, 1.0, 0.0);
		glVertex3f(-1.0, -1.0, 0.0);
		glVertex3f(1.0, -1.0, 0.0);
		glVertex3f(2.0, 1.0, 0.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 2, GL_COMPILE);
	glBegin(GL_LINE_STRIP);
	{
		glVertex3f(0.0, 1.0, 0.0);
		glVertex3f(-1.0, -1.0, 0.0);
		glVertex3f(1.0, -1.0, 0.0);
		glVertex3f(2.0, 1.0, 0.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 3, GL_COMPILE);
	glBegin(GL_LINE_LOOP);
	{
		glVertex3f(0.0, 1.0, 0.0);
		glVertex3f(-1.0, -1.0, 0.0);
		glVertex3f(1.0, -1.0, 0.0);
		glVertex3f(2.0, 1.0, 0.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 4, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		glVertex3f(0.0, 1.0, 0.0);
		glVertex3f(-1.0, -1.0, 0.0);
		glVertex3f(1.0, -1.0, 0.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 5, GL_COMPILE);
	glBegin(GL_TRIANGLE_STRIP);
	{
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-1.0, 2.0, 0.0);
		glVertex3f(-2.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-1.0, -2.0, 0.0);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(1.0, -2.0, 0.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 6, GL_COMPILE);
	glBegin(GL_TRIANGLE_FAN);
	{
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(0.0, -1.0, 0.0);
		glVertex3f(-1.0, 1.0, 0.0);
		glVertex3f(1.0, 1.0, 0.0);

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(2.0, -1.0, 0.0);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0, -2.0, 0.0);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-1.0, -1.0, 0.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 7, GL_COMPILE);
	glBegin(GL_QUADS);
	{
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0, -1.0, 0.0);

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-1.0, 1.0, 0.0);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(1.0, 1.0, 0.0);

		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(2.0, -1.0, 0.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 8, GL_COMPILE);
	glBegin(GL_QUAD_STRIP);
	{
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-0.5, 1.0, 0.0);

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.5, 1.0, 0.0);

		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-0.5, 0.0, 0.0);

		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(0.5, 0.0, 0.0);

		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0, -1.0, 0.0);

		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(0.0, -1.5, 0.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 9, GL_COMPILE);
	glBegin(GL_POLYGON);
	{
		glVertex3f(0.0, 1.0, 0.0);
		glVertex3f(-1.0, -1.0, 0.0);
		glVertex3f(1.0, -1.0, 0.0);
	}
	glEnd();
	glEndList();

	loadModel();
}

void Game::loadModel()
{
	sf::Vector3f vertices[]
	{
		{ 1.0, 1.0, -1.0 },
		{ 1.0, -1.0, -1.0 },
		{ 1.0, 1.0, 1.0 },
		{ 1.0, -1.0, 1.0 },
		{ -1.0, 1.0, -1.0 },
		{ -1.0, -1.0, -1.0 },
		{ -1.0, 1.0, 1.0 },
		{ -1.0, -1.0, 1.0 }
	};

	int facesIndices[6][4]
	{
		{1, 5, 7, 3},
		{4, 3, 7, 8},
		{8, 7, 5, 6},
		{6, 2, 4, 8},
		{2, 1, 3, 4},
		{6, 5, 1, 2}
	};

	glNewList(index + 10, GL_COMPILE);
	for (int row = 0; row < 6; row++)
	{
		glColor3f(rand() / static_cast<float>(RAND_MAX), rand() / static_cast<float>(RAND_MAX), rand() / static_cast<float>(RAND_MAX));
		glBegin(GL_QUADS);
		{
			for (int col = 0; col < 4; col++)
			{
				glVertex3f(vertices[facesIndices[row][col] - 1].x, vertices[facesIndices[row][col] - 1].y, vertices[facesIndices[row][col] - 1].z);
			}
		}
		glEnd();
	}
	glEndList();
}

void Game::update()
{
	// Rotations
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		glRotatef(0.5f, 0.0f, 0.0f, 1.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
	{
		glRotatef(0.5f, 0.0f, 1.0f, 0.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		glRotatef(0.5f, 1.0f, 0.0f, 0.0f);
	}

	// Translations
	float speed = 0.05f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		glTranslatef(speed, 0.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		glTranslatef(-speed, 0.0f, 0.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		glTranslatef(0.0f, speed, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		glTranslatef(0.0f, -speed, 0.0f);
	}

	// Scales
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		m_scale += 0.05f;
		std::cout << m_scale << std::endl;
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
	{
		m_scale -= 0.05f;
		std::cout << m_scale << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
	{
		m_scale = 1.0f;
		std::cout << m_scale << std::endl;
	}
	glScalef(m_scale, m_scale, m_scale);
}

void Game::draw()
{
	// Clear all open gl primatives
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Call the list and draw the current primative
	glCallList(current);

	// Display the window
	window.display();
}

void Game::unload()
{
	//cout << "Cleaning up" << endl;
}
