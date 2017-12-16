#pragma once
class IPlayerComponent
{
public:
	virtual ~IPlayerComponent() = 0;
	virtual void Update() = 0;
};

