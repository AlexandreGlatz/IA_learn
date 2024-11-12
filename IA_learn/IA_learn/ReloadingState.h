#pragma once
#include "State.h"

class Gun;

class ReloadingState : public State
{
public:
	ReloadingState(Gun* pGun);
	~ReloadingState();
	void Start();
	void Update(float deltaTime);

private:
	Gun* m_pGun;
};

