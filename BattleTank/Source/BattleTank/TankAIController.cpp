// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Tank.h"
// Depends on MovementComponent via pathfinding

void ATankAIController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnDeath);
	}
}

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

	// Fire if ready
	if (ControlledPawnAimingComponent->GetFiringStatus() == EFiringStatus::Fixed)
	{
		ControlledPawnAimingComponent->Fire();
	}
}

void ATankAIController::OnDeath()
{
	UE_LOG(LogTemp, Warning, TEXT("%s died!"), *GetPawn()->GetName());
	GetPawn()->DetachFromControllerPendingDestroy();
}



