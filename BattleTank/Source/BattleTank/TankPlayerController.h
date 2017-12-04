// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last include

class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	private:
		UPROPERTY(EditDefaultsOnly)
		float CrossHairXLocation = 0.5f;

		UPROPERTY(EditDefaultsOnly)
		float CrossHairYLocation = 0.33333f;

		UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000.f; // UE4 is in centimeters!

		UTankAimingComponent* AimingComponent = nullptr;

		void AimTowardsCrosshair(); // Start the tank moving the barrel so that a shot would hit at crosshair
		bool GetSightRayHitLocation(FVector& OutHitLocation) const;
		bool GetLookDirection(FVector2D ScreenLocation, FVector & OutLookDirection) const;
		bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;

	protected:
		virtual void BeginPlay() override;

		UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimComponentReference); // No need to implement, the parameter is the return type (lol)

		void OnDeath();

	public:
		// Called every frame
		virtual void Tick(float DeltaTime) override;

		virtual void SetPawn(APawn * InPawn) override;
};
