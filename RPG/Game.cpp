#include "Game.h"
#include "GameState.h"

//STATIC FUNCS

//INITALIZORS
void Game::initWindow()
{
	//TODO: CREATE THE WINDOW WITH A "WINDOW.INI" FILE
	std::ifstream ifs("Config/window.ini");
	sf::VideoMode window_bounds(800, 600);
	std::string title = "None";
	unsigned framerate_limit = 120;
	bool vertical_sync_enabled = false;

	if (ifs.is_open()) {
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;
	}

	ifs.close();
	this ->window = new sf::RenderWindow(window_bounds, title);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initStates()
{
	this->states.push(new GameState(this->window));
}

//CONSTRUCTERS/DESTRUCTERS

Game::Game()
{
	this->initWindow();
	this->initStates();
}

Game::~Game()
{
	delete this->window;

	while (!this->states.empty()) {
		delete this->states.top();
		this->states.pop();
	}
}

//Funcs
void Game::UpdateSFMLEvents()
{
	while (this->window->pollEvent(this->sfEVent))
	{
		if (sfEVent.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::update()
{
	this->UpdateSFMLEvents();

	if (!this->states.empty()) {
		this->states.top()->update(this->dt);

		if (this->states.top()->getQuit()) {
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}

	//Quitting Game
	else {
		this->window->close();
	}
}

void Game::render()
{
	this->window->clear();

	//Render Items
	if (!this->states.empty())
		this->states.top()->render();

	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDT();
		this->update();
		this->render();
	}

}

void Game::updateDT()
{
	this->dt = this->dtClock.restart().asSeconds(); // Updates the "dt" variable with the time it takes to render and update one frame

}