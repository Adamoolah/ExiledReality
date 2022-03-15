#pragma once

#include"GameState.h"

class Game
{
private:
	//VARIABLES
	sf::RenderWindow *window;
	sf::Event sfEVent;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	//INITALIZATION
	void initWindow();
	void initStates();

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

