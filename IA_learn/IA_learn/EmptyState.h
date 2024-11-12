#pragma once
#include "State.h"

class Gun;

class EmptyState : public State
{
public:
	EmptyState(Gun* pGun);
	~EmptyState();
	void Start();
	void Update(float deltaTime);

private:
	Gun* m_pGun;
};

