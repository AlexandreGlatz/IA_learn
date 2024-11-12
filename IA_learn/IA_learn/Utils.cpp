#include "Utils.h"

char HandleInput()
{
	if (_kbhit())
	{
		char key = _getch();
		return key;
	}
}
