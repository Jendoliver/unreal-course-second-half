// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"
#include "TankAimingComponent.h"
// Depends on MovementComponent via pathfinding

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ControlledPawnAimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!ensure(ControlledPawnAimingComponent && PlayerPawn)) { return; }

	// Move towards the player
	MoveToActor(PlayerPawn, AcceptanceRadius);

	// Aim towards the player
	ControlledPawnAimingComponent->AimAt(PlayerPawn->GetActorLocation());

	// TODO FIX Fire if ready
	// ControlledPawnAimingComponent->Fire();
}



