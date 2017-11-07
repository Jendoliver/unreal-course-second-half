// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
	private:
		UTankAimingComponent* ControlledPawnAimingComponent = nullptr;
		APawn* PlayerPawn = nullptr;

		// How close to the player can the AI tank drive
		UPROPERTY(EditDefaultsOnly)
		float AcceptanceRadius = 3000.f;

	protected:
		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;
};
