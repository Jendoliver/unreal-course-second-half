// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	virtual void BeginPlay() override;

	FTankDelegate OnDeath;

	// Returns current tank health as a percentage of starting health between 0 and 1
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;

private:

	UPROPERTY(EditDefaultsOnly, Category = "Status")
	int32 StartingHealth = 100.f;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth;
};
