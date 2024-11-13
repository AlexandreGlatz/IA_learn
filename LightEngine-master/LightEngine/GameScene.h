#pragma once
#include "Scene.h"
#include "Plant.h"

class GameScene : public Scene
{
	

private:
	void TrySetSelectedEntity(Entity* pEntity, int x, int y);
	std::vector<Entity*> m_plant;
	Entity* pEntitySelected;
	enum class TagType
	{
		PlantType,
		ZombieType,
		BallType
	};
public:
	void Initialize() override;
	void HandleInput(const sf::Event& event) override;
	void Update() override;
};

