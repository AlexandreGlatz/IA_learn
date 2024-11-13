#include "Plant.h"
#include "Ball.h"

Plant::Plant(float radius, sf::Color color)
	:m_pv(10), Entity(radius, color)
{
	m_radius = radius;
}

Plant::~Plant()
{}

void Plant::Shoot()
{
	Entity* pBall = GetScene()->CreateEntity<Ball>(15, sf::Color::Red);
	pBall->SetPosition(GetPosition(0.5,0.5).x, GetPosition(0.5,0.5).y, 0.5, 0.5);
	pBall->SetTag(2);
}


