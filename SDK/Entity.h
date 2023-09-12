#pragma once

#include "../ProcessUtil.h"

class Entity
{
public:
	Entity(uintptr_t address) : entityAddress{ address } {};

	int getHealth()
	{
		if (!entityAddress)
			return -1;

		return csgo->read<int>(this->entityAddress + Offsets::m_iHealth);
	}

	int getLifeState()
	{
		if (!entityAddress)
			return -1;

		return csgo->read<int>(this->entityAddress + Offsets::m_lifeState);
	}

	int getFlags()
	{
		if (!entityAddress)
			return -1;

		return csgo->read<int>(this->entityAddress + Offsets::m_fFlags);
	}

	bool isAlive()
	{
		return getHealth() > 0 && getLifeState() == 0;
	}

	bool isOnGround()
	{
		return getFlags() & (1 << 0);
	}

	bool isValid()
	{
		return this->entityAddress != NULL;
	}
private:
	uintptr_t entityAddress;
};

class LocalPlayer : Entity
{
public:
	LocalPlayer(uintptr_t clientAddress) : clientAddress{ clientAddress }, Entity(csgo->read<uintptr_t>(clientAddress + Offsets::dwLocalPlayer)) {};

	void jump()
	{
		if (!clientAddress)
			return;

		csgo->write<int>(this->clientAddress + Offsets::dwForceJump, 6);
	}

	Entity* toEntity()
	{
		return reinterpret_cast<Entity*>(this);
	}
private:
	uintptr_t clientAddress;
};