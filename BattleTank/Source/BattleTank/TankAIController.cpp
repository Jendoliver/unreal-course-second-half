// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ControlledTank = Cast<ATank>(GetPawn());
	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (ControlledTank && PlayerTank)
	{
		// Move towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation()); // Aim towards the player
		// Fire if ready
		ControlledTank->Fire();
	}
}



