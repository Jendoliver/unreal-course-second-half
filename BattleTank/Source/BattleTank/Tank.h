// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

	public:
		// Sets default values for this pawn's properties
		ATank();
		/* TODO MAKE IT WORK AGAIN
		UFUNCTION(BlueprintCallable, Category = Action)
		void Fire();
		*/
	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

	private:	
		UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;

		// TODO remove when firing is moved to AimingComponent
		UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSpeed = 10000.f;

		UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTimeInSeconds = 3.f;

		float LastFireTime = 1.f;
};
