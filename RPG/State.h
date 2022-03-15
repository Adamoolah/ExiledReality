#pragma once

#include"SFML/Graphics.hpp"
#include"SFML/Window.hpp"
#include"SFML/System.hpp"
#include"SFML/Audio.hpp"
#include"SFML/Network.hpp"


#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include<stack>
#include<map>
#include<vector>

class State
{
private:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
public:
	State(sf::RenderWindow* window);
	virtual ~State();

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target = nullptr) = 0;

	virtual void endState() = 0;
};

