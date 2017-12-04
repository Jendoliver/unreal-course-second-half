// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

float ATank::GetHealthPercent() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}

float ATank::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser)
{
	const float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	int32 DamagePoints = FPlatformMath::RoundToInt(ActualDamage);
	if (DamagePoints > 0)
	{
		if (DamagePoints < CurrentHealth)
		{
			CurrentHealth -= DamagePoints;
		}
		else
		{
			CurrentHealth = 0;
		}

		// If the damage depletes our health set our lifespan to zero - which will destroy the actor  
		if (CurrentHealth <= 0)
		{
			SetLifeSpan(0.001f);
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("Damage: %d, CurrentHealth: %d"), DamagePoints, CurrentHealth);
	return DamagePoints;
}

