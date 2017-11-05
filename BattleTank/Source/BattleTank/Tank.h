// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

	public:
		// Sets default values for this pawn's properties
		ATank();
		void AimAt(FVector HitLocation);

		UFUNCTION(BlueprintCallable, Category = Action)
		void Fire();

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

		UPROPERTY(BlueprintReadOnly)
		UTankAimingComponent* TankAimingComponent = nullptr;

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
