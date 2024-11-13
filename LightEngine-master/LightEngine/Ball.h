#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
class Ball : public Entity
{
public:
	Ball(float radius, sf::Color color);
	~Ball();

	void OnUpdate() override;	
};

