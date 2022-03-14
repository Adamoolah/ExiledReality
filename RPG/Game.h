#pragma once

#include"State.h"

class Game
{
private:
	//VARIABLES
	sf::RenderWindow *window;
	sf::Event sfEVent;

	sf::Clock dtClock;
	float dt;

	//INITALIZATION
	void initWindow();

public:
	//cONSTRUCTERS/DESTRUCTERS
	Game();
	virtual ~Game();

	//Fuctions
	void UpdateSFMLEvents();
	void update();
	void render();
	void run();
	void updateDT();
};

