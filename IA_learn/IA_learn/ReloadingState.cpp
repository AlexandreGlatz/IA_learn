#include "ReloadingState.h"
#include "Gun.h"

ReloadingState::ReloadingState(Gun* pGun) : m_pGun(pGun)
{
}

ReloadingState::~ReloadingState()
{
}

void ReloadingState::Start()
{
	if (m_pGun->TransitionTo(Gun::StateEnum::Reloading) == false)
		return;

	std::cout << "Current state : Reloading, current ammo = " << m_pGun->GetAmmo() << std::endl;
}

void ReloadingState::Update(float deltaTime)
{
	m_pGun->m_reloadProgress += deltaTime;
	if (m_pGun->m_reloadProgress > m_pGun->m_reloadTime)
	{
		m_pGun->m_reloadProgress = 0.0;
		m_pGun->SetAmmo(m_pGun->GetCapacity());
		m_pGun->TransitionTo(Gun::StateEnum::Idle);
	}
}


