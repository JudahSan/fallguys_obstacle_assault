// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();	

	// Set startlocation. Reference class variable

	StartLocation = GetActorLocation();

}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	// TO:DO
	// Update the CurrentLocation: Use X or Y member. Add to it and assign back. Move the platform to it's start location. Compile and test

	// Move platform forward
		// Get current location
	FVector CurrentLocation = GetActorLocation();
		// Add vector to that location
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		// Set the location
	SetActorLocation(CurrentLocation);
	// Send platform back if gone too far
		// Check how far we've moved
	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);
		
		// Reverse direction of motion if gone too far

	if (DistanceMoved > MoveDistance) 
	{
		
		// Get normal of the vector
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		// Update start location of we reached the end of our travel
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		// Reverse Direction
		PlatformVelocity = -PlatformVelocity;
	}
}