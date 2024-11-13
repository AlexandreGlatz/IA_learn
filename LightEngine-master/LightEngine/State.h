#pragma once

class Gun;

class State
{
public:
	virtual ~State() = 0;

	virtual void Start() = 0;
	virtual void Update() = 0;
};
