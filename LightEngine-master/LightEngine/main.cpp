
#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameManager.h"
#include "GameScene.h"

#include <cstdlib>
#include <crtdbg.h>

int main() 
{
	srand(time(NULL));
    GameManager* pInstance = GameManager::Get();

	pInstance->CreateWindow(800, 800, "SampleScene");
	
	pInstance->LaunchScene<GameScene>();

	return 0;
}