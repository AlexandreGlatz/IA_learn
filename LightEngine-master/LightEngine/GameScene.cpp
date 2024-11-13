#include "GameScene.h"

void GameScene::Initialize()
{
	//Plant creation
	for (int i = 0; i < 3; i++) 
	{
		Entity* pPlant = CreateEntity<Plant>(50, sf::Color::Green);
		pPlant->SetPosition(20, 200 + i * 150);
		pPlant->SetTag((int)GameScene::TagType::PlantType);
		m_plant.push_back(pPlant);
	}
}

void GameScene::HandleInput(const sf::Event& event)
{
	if (event.type != sf::Event::EventType::MouseButtonPressed)
		return;

	if (event.mouseButton.button == sf::Mouse::Button::Right)
	{
		for (size_t i = 0; i < m_plant.size(); ++i)
			TrySetSelectedEntity(m_plant[i], event.mouseButton.x, event.mouseButton.y);
	}

	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		if (pEntitySelected != nullptr)
		{
			pEntitySelected->GoToPosition(event.mouseButton.x, event.mouseButton.y, 100.f);
		}
	}
}

void GameScene::Update()
{
	if (pEntitySelected != nullptr)
	{
		static_cast<Plant*>(pEntitySelected)->Shoot();
		pEntitySelected = nullptr;
	}
}


void GameScene::TrySetSelectedEntity(Entity* pEntity, int x, int y)
{
	if (pEntity->IsInside(x, y) == false)
		return;

	pEntitySelected = pEntity;
}