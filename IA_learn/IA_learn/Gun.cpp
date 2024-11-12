#include "Gun.h"
#include "Utils.h"
#include "State.h"

Gun::Gun()
	:m_ammo(10),
	m_capacity(10),
	m_reloadProgress(0.0),
	m_shootProgress(0.0),
	m_shootTime(2.0),
	m_reloadTime(10.0),
	m_state(Gun::StateEnum::Idle)
{
	State* pIdle = new IdleState(this);
	m_statesTab[0] = pIdle;

	State* pShooting = new ShootingState(this);
	m_statesTab[1] = pShooting;

	State* pReload = new ReloadingState(this);
	m_statesTab[2] = pReload;

	State* pEmpty = new EmptyState(this);
	m_statesTab[3] = pEmpty;

}

Gun::~Gun()
{

}

void Gun::Update(float deltaTime)
{

}


void Gun::Shoot()
{

}

void Gun::Reload()
{


}

bool Gun::TransitionTo(StateEnum to)
{
	if (m_transition[(int)m_state][(int)to] == false)
		return false;

	m_state = to;

	return true;
}