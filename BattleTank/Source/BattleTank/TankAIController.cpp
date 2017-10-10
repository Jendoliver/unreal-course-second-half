// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* ControlledTank = GetControlledTank();
	ATank* PlayerControllerTank = GetPlayerTank();
}

ATank* ATankAIController::GetControlledTank() const
{
	ATank* ControlledTank = Cast<ATank>(GetPawn());
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController is controlling the pawn %s"), *(ControlledTank->GetName()))
			return ControlledTank;
	}
	UE_LOG(LogTemp, Error, TEXT("TankAIController can't get the ATank* ControlledTank"))
		return nullptr;
}

ATank * ATankAIController::GetPlayerTank() const
{
	ATank* PlayerPawn = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("Got the PlayerControllerTank! %s"), *(PlayerPawn->GetName()))
			return PlayerPawn;
	}
	UE_LOG(LogTemp, Error, TEXT("TankAIController can't get the PlayerControllerTank"))
	return nullptr;
}



