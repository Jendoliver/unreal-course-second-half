// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	private:
		UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5;

		UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.33333;

		UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000; // UE4 is in centimeters!

		ATank* ControlledTank = nullptr;

		ATank* GetControlledTank() const;
		void AimTowardsCrosshair(); // Start the tank moving the barrel so that a shot would hit at crosshair
		bool GetSightRayHitLocation(FVector& OutHitLocation) const;
		bool GetLookDirection(FVector2D ScreenLocation, FVector & OutLookDirection) const;
		bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;

	protected:
		virtual void BeginPlay() override;

	public:
		// Called every frame
		virtual void Tick(float DeltaTime) override;
};
