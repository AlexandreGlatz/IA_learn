#pragma once
#include "State.h"

class Gun;

class ShootingState : public State
{
public:
	ShootingState(Gun* pGun);
	~ShootingState() override;

	void Start() override;
	void Update(float deltaTime) override;
private:
	Gun* m_pGun;
};

