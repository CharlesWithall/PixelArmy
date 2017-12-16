#include "Soldier.h"
#include "DEBUG.h"
#include "FightBehaviour.h"
#include "FindTargetBehaviour.h"
#include "MoveOnAxisBehaviour.h"
#include "MoveToPointBehaviour.h"

Soldier::Soldier(Player* const aPlayer) : 
	myPlayer(aPlayer),
	GameEntity(*aPlayer->GetWorldModel()->GetAsset()->GetMeleeSoldierTexture(), sf::Vector2f(0, 0))
{
	mySoldierDamage = myStartingDamage;
	mySoldierHealth = myStartingHealth;
	mySoldierSpeed = myStartingSpeed;
	myAttackSpeed = myStartingAttackSpeed;
}

Soldier::Soldier(Player* const aPlayer, Soldier* const aPrototype, const int& aSpawnLocation) :
	GameEntity(*aPlayer->GetWorldModel()->GetAsset()->GetMeleeSoldierTexture(), sf::Vector2f(aPlayer->GetWorldModel()->GetCoordinates()->GetBackline(), aSpawnLocation), sf::Vector2f(aPrototype->GetSoldierHealth() * 0.02f, aPrototype->GetSoldierHealth() * 0.02f))
{
	Init(aPlayer, aPrototype, aSpawnLocation);
}

void Soldier::Init(Player* const aPlayer, Soldier* const aPrototype, const int& aSpawnLocation)
{
	myPlayer = aPlayer;
	mySoldierDamage = aPrototype->GetSoldierDamage();
	mySoldierHealth = aPrototype->GetSoldierHealth();
	mySoldierSpeed = aPrototype->GetSoldierSpeed();
	myAttackSpeed = aPrototype->GetAttackSpeed();

	myTargetSoldier = nullptr;
	InitBehaviours(aPlayer);
}

void Soldier::InitBehaviours(Player* const aPlayer)
{
	myBehaviours.clear();
	sf::Vector2f movementVector;

	switch (aPlayer->GetPlayerID())
	{
	case PlayerID::PlayerOne:
		movementVector = sf::Vector2f(mySoldierSpeed, 0);
		break;
	case PlayerID::PlayerTwo:
		movementVector = sf::Vector2f(-mySoldierSpeed, 0);
		break;
	default:
		DEBUG::Log("Illegal Player Passed into Soldier Constructor!");
	}

	// Behaviour Hierarchy
	myBehaviours.push_back(new FightBehaviour()); 
	myBehaviours.push_back(new MoveToPointBehaviour(mySoldierSpeed));
	myBehaviours.push_back(new FindTargetBehaviour());
	myBehaviours.push_back(new MoveOnAxisBehaviour(movementVector));
}

void Soldier::AttackTarget()
{
	if (myTargetSoldier)
		myTargetSoldier->ReceiveDamage(mySoldierDamage);
}

void Soldier::ReceiveDamage(const int& aDamageAmount)
{
	mySoldierHealth -= aDamageAmount;

	if (mySoldierHealth <= 0)
		EmbraceDeath();
}

void Soldier::EmbraceDeath()
{
	SetIsActive(false);
}

void Soldier::Recycle(Soldier* aPrototypeSoldier, const int& aYPosition)
{
	Init(myPlayer, aPrototypeSoldier, aYPosition);
	GameEntity::Init(*myPlayer->GetWorldModel()->GetAsset()->GetMeleeSoldierTexture(), sf::Vector2f(myPlayer->GetWorldModel()->GetCoordinates()->GetBackline(), aYPosition), sf::Vector2f(aPrototypeSoldier->GetSoldierHealth() * 0.02f, aPrototypeSoldier->GetSoldierHealth() * 0.02f));
}