// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringStatus : uint8
{ 
	Reloading, 
	Aiming,
	Fixed 
};

class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	// Takes the references for the barrel and the turret
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation);

	inline bool IsBarrelMoving() { return bBarrelMoving; }
	inline void SetBarrelMoving(bool bBarrelMoving) { this->bBarrelMoving = bBarrelMoving; }

	// Input binded function to fire (used by the player and the AI)
	UFUNCTION(BlueprintCallable, Category = "Action")
	void Fire();

protected:
	// Whether the tank is ready to fire or not, used to draw the reticle
	UPROPERTY(BlueprintReadOnly, Category = "Firing State")
	EFiringStatus FiringStatus = EFiringStatus::Fixed;

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	// The speed which the projectile is launch at
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000.f;

	// The projectile blueprint for this component
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	// The time it takes for the tank to reload
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeInSeconds = 3.f;

	float LastFireTime = 0.f;

	void MoveBarrelTowards(FVector AimDirection);
	void MoveTurretTowards(FVector AimDirection);

	FVector AimDirection;

	bool bBarrelMoving = false;
};
