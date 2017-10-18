// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAimingComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component")); // This adds a component to the blueprint which we can see in the editor
}

void ATank::SetBarrelReference(UTankBarrel* BarrelRef)
{
	TankAimingComponent->SetBarrelReference(BarrelRef);
}

void ATank::SetTurretReference(UTankTurret* TurretRef)
{
	TankAimingComponent->SetTurretReference(TurretRef);
}

void ATank::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("FIRE IN THA HOLA"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

