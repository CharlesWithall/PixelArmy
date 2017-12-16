#pragma once

#include "GameEntity.h"
#include "Player.h"

class BehaviourComponent;

class Soldier : public GameEntity
{
public:
	Soldier(Player* const aPlayer);
	Soldier(Player* const aPlayer, Soldier* const aPrototype, const int& aSpawnLocation);
	~Soldier() {}

	void Init(Player* const aPlayer, Soldier* const aPrototype, const int& aSpawnlocation);

	void AttackTarget();
	void EmbraceDeath();
	void ReceiveDamage(const int& aDamageAmount);
	void Recycle(Soldier* aPrototypeSoldier, const int& aYPosition);

	const int GetSoldierDamage() { return mySoldierDamage; }
	const int GetSoldierHealth() { return mySoldierHealth; }
	const int GetSoldierSpeed() { return mySoldierSpeed; }
	const float GetAttackSpeed() { return myAttackSpeed; }
	const PlayerID& GetOwner() { return myPlayer->GetPlayerID(); }
	Soldier* GetTarget() { return myTargetSoldier; }

	void SetTarget(Soldier* const aTargetSoldier) { myTargetSoldier = aTargetSoldier; }
private:
	void InitBehaviours(Player* const aPlayer);

	BehaviourComponent* myBehaviourComponent;

	Soldier* myTargetSoldier;
	Player* myPlayer;
	int mySoldierDamage;
	int mySoldierHealth;
	int mySoldierSpeed;
	float myAttackSpeed;
	bool myIsRanged;

	const int myStartingDamage = 10;
	const int myStartingHealth = 10;
	const int myStartingSpeed = 1;
	const float myStartingAttackSpeed = 2.5f;
};

