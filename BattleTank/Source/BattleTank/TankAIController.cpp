// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ControlledTank = GetControlledTank();
	PlayerTank = GetPlayerTank();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (ControlledTank)
	{
		// Move towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation()); // Aim towards the player
		// Fire if ready
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	ATank* NewControlledTank = Cast<ATank>(GetPawn());
	if (NewControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController is controlling the pawn %s"), *(NewControlledTank->GetName()))
			return NewControlledTank;
	}
	UE_LOG(LogTemp, Error, TEXT("TankAIController can't get the ATank* ControlledTank"))
		return nullptr;
}

ATank* ATankAIController::GetPlayerTank() const
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



