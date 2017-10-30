// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

	public:
		// Sets default values for this pawn's properties
		ATank();
		void AimAt(FVector HitLocation);

		UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelReference(UTankBarrel* BarrelRef);

		UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretReference(UTankTurret* TurretRef);

		UFUNCTION(BlueprintCallable, Category = Action)
		void Fire();

		// Called to bind functionality to input
		virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;
		UTankAimingComponent* TankAimingComponent = nullptr;

		UPROPERTY(BlueprintReadOnly)
		UTankMovementComponent* TankMovementComponent = nullptr;

	private:	
		UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;

		UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSpeed = 10000; // TODO find sensible default

		UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTimeInSeconds = 3;

		float LastFireTime = 0;

		// Local barrel ref to spawn projectile
		UTankBarrel* Barrel = nullptr;
};
