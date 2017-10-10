// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ATank* ControlledTank = GetControlledTank();
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
