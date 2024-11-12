#pragma once
#include <iostream>
#include <vector>
#include "State.h"
#include "IdleState.h"
#include "ReloadingState.h"
#include "EmptyState.h"
#include "ShootingState.h"
class Gun
{
public:
	enum class StateEnum
	{
		Idle,
		Shooting,
		Empty,
		Reloading,

		StateCount
	};

	static const int STATE_COUNT = (int)StateEnum::StateCount;

	bool TransitionTo(StateEnum To);

private:
	StateEnum m_state;

	int m_transition[STATE_COUNT][STATE_COUNT] =
	{
		//Idle, Shooting, Empty, Reloading
		{  0,       1,       0,       1}, //Idle
		{  1,       0,       1,       0}, //Shooting
		{  0,       0,       0,       1}, //Empty
		{  1,       0,       0,       0}, //Reloading
	};

	State* m_statesTab[STATE_COUNT];
public:

	Gun();
	~Gun();

	void Update(float deltaTime);
	void Shoot();
	void Reload();

	void AddAmmo(int added) { m_ammo += added; }
	void SetAmmo(int ammo) { m_ammo = ammo; }
	int GetAmmo() { return m_ammo; }

	int GetCapacity() { return m_capacity; }

	float m_reloadTime, m_shootTime, m_reloadProgress, m_shootProgress;
private:
	int m_ammo;
	int m_capacity;
};

