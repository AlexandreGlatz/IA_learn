#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
class Zombie : public Entity
{
public:
	Zombie(float radius = 50, sf::Color color = sf::Color::Red);
	~Zombie();

	void OnUpdate() override;
private:


};

