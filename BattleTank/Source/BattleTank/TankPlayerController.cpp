// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ControlledTank = GetControlledTank();
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (ControlledTank)
	{
		AimTowardsCrosshair();
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	ATank* NewControlledTank = Cast<ATank>(GetPawn());
	if (NewControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController is controlling the pawn %s"), *(NewControlledTank->GetName()))
		return NewControlledTank;
	}
	UE_LOG(LogTemp, Error, TEXT("TankPlayerController can't get the ATank* ControlledTank"))
	return nullptr;
}

void ATankPlayerController::AimTowardsCrosshair()
{
	FVector HitLocation; // OUT
	if (GetSightRayHitLocation(HitLocation)) // has side effect, line traces
	{
		ControlledTank->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	FVector LookDirection;

	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		return GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}
	OutHitLocation = FVector(0);
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& OutLookDirection) const
{
	FVector WorldLocation;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		WorldLocation,
		OutLookDirection
	);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const
{
	FHitResult OutHitResult;
	FVector StartLocation = PlayerCameraManager->GetCameraLocation(); // Very important not to take the tank as the start, since it's the camera!
	FVector EndLocation = StartLocation + LookDirection * LineTraceRange;

	if (GetWorld()->LineTraceSingleByChannel(OutHitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		OutHitLocation = OutHitResult.Location;
		return true;
	}
	OutHitLocation = FVector(0);
	return false;
}