#include "Game.h"

//STATIC FUNCS

//INITALIZORS
void Game::initWindow()
{
	//TODO: CREATE THE WINDOW WITH A "WINDOW.INI" FILE
	this ->window = new sf::RenderWindow(sf::VideoMode(200, 200), "Exiled Reality");
}

//CONSTRUCTERS/DESTRUCTERS

Game::Game()
{
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
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
}

void Game::render()
{
	this->window->clear();

	//Render Items

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

	system("cls");
	std::cout << this->dt << "\n"; 
}
