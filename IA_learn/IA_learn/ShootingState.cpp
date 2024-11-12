#include "ShootingState.h"
#include "Gun.h"

ShootingState::ShootingState(Gun* pGun): m_pGun(pGun)
{
}

ShootingState::~ShootingState()
{
}

void ShootingState::Start()
{
	if (m_pGun->TransitionTo(Gun::StateEnum::Shooting) == false)
		return;
	 m_pGun->AddAmmo(-1);
	std::cout << "Current state : Shooting, current ammo = " << m_pGun->GetAmmo() << std::endl;
}

void ShootingState::Update(float deltaTime)
{
	m_pGun->m_shootProgress += deltaTime;
	if (m_pGun->m_shootProgress > m_pGun->m_shootTime)
	{
		m_pGun->m_shootProgress = 0.0;
		m_pGun->TransitionTo(Gun::StateEnum::Idle);
	}
}
