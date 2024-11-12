#pragma once
#include "State.h"

class Gun;

class IdleState : public State
{
public:
	IdleState(Gun* pGun);
	~IdleState();
	void Start();
	void Update(float deltaTime);

private:
	Gun* m_pGun;
};

