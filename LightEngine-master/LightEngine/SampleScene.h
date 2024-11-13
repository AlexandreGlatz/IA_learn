#pragma once

#include "Scene.h"

class DummyEntity;

class SampleScene : public Scene
{
	std::vector<DummyEntity*> m_entities;
	DummyEntity* pEntitySelected;

private:
	void TrySetSelectedEntity(DummyEntity* pEntity, int x, int y);

public:
	void Initialize() override;
	void HandleInput(const sf::Event& event) override;
	void Update() override;
};


