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
		ATank* GetControlledTank() const;
		void AimTowardsCrosshair(); // Start the tank moving the barrel so that a shot would hit at crosshair
		bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	protected:
		virtual void BeginPlay() override;

	public:
		// Called every frame
		virtual void Tick(float DeltaTime) override;
};
