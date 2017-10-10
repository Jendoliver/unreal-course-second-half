// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ATank* ControlledTank = GetControlledTank();
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	ATank* ControlledTank = Cast<ATank>(GetPawn());
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController is controlling the pawn %s"), *(ControlledTank->GetName()))
		return ControlledTank;
	}
	UE_LOG(LogTemp, Error, TEXT("TankPlayerController can't get the ATank* ControlledTank"))
	return nullptr;
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // OUT
	if (GetSightRayHitLocation(HitLocation)) // has side effect, line traces
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString())
		// TODO: Tell controlled tank to aim at this point
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Trace line projection from 2D crosshair to 3D world (Get screen location to world)
	// If it hits the landscape
		// OutHitLocation = Hit
		// return true
	return false;
}