#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
class Plant : public Entity
{
public:
	Plant(float radius, sf::Color color);
	~Plant();

	//void OnUpdate() override;
	void Shoot();

private:
	int m_pv;
	float m_radius;
};

