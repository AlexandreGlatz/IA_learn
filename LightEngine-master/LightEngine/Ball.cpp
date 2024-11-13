#include "Ball.h"

Ball::Ball(float radius, sf::Color color) : Entity(radius, color)
{
}

Ball::~Ball()
{
}

void Ball::OnUpdate()
{
	SetDirection(1, 0, 100);

	if (GetPosition().x > GetScene()->GetWindowWidth())
		Destroy();
}
