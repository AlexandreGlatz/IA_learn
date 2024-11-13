#include "SampleScene.h"

#include "DummyEntity.h"

#include "Debug.h"

void SampleScene::Initialize()
{
	for (int i = 0; i < 10; ++i)
	{
		DummyEntity* pEntity;
		if (i >= 5)
		{
			pEntity = CreateEntity<DummyEntity>((rand() % 15) + 15, sf::Color::Red);
			pEntity->SetPosition((rand() % 100) + 650, (rand() % 100) + 25);
		}
		else
		{
			pEntity = CreateEntity<DummyEntity>((rand() % 15) + 15, sf::Color::Blue);
			pEntity->SetPosition((rand() % 100) + 25, (rand() % 100) + 650);
		}
		m_entities.push_back(pEntity);
	}

	pEntitySelected = nullptr;
}

void SampleScene::HandleInput(const sf::Event& event)
{
	if (event.type != sf::Event::EventType::MouseButtonPressed)
		return;

	if (event.mouseButton.button == sf::Mouse::Button::Right)
	{
		for (size_t i = 0; i < m_entities.size(); ++i)
			TrySetSelectedEntity(m_entities[i], event.mouseButton.x, event.mouseButton.y);
	}

	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		if (pEntitySelected != nullptr) 
		{
			pEntitySelected->GoToPosition(event.mouseButton.x, event.mouseButton.y, 100.f);
		}
	}
}

void SampleScene::TrySetSelectedEntity(DummyEntity* pEntity, int x, int y)
{
	if (pEntity->IsInside(x, y) == false)
		return;

	pEntitySelected = pEntity;
}

void SampleScene::Update()
{
	if(pEntitySelected != nullptr)
	{
		sf::Vector2f position = pEntitySelected->GetPosition(0.5f, 0.5f);
		Debug::DrawCircle(position.x, position.y, 10, sf::Color::Blue);
	}
}