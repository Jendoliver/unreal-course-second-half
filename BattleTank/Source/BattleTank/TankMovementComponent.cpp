// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!ensure(LeftTrackToSet && RightTrackToSet)) { return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	LeftTrack->SetTrackThrottle(Throw);
	RightTrack->SetTrackThrottle(Throw);
}

void UTankMovementComponent::IntendTurn(float Throw)
{
	LeftTrack->SetTrackThrottle(Throw);
	RightTrack->SetTrackThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	auto AIForwardVector = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(AIForwardVector, AIForwardIntention);
	IntendMoveForward(ForwardThrow);

	auto TurnThrow = FVector::CrossProduct(AIForwardVector, AIForwardIntention).Z;
	IntendTurn(TurnThrow);
}
