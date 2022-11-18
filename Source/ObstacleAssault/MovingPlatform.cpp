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

	// FString
	//FString MyString = "My String Value";

	// Output logs

	// UE_LOG(LogTemp, Display, TEXT("Configured Moved Distance: %f"), MoveDistance);
	
	// UE_LOG(LogTemp, Display, TEXT("Here's My String: %s"), *MyString);


	// %s -> *FString

	FString Name = GetName();

	UE_LOG(LogTemp, Display, TEXT("BeginPlay: %s"), *Name);

}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);

	RotatePlatform(DeltaTime);

}

void AMovingPlatform::MovePlatform(float DeltaTime)
{

	if (ShouldPlatformReturn()) 
	{

		// Get normal of the vector
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		// Update start location of we reached the end of our travel
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		// Reverse Direction
		PlatformVelocity = -PlatformVelocity;
	} 
	else 
	{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		SetActorLocation(CurrentLocation);
	}
}

// Rotate platform function
void AMovingPlatform::RotatePlatform(float DT)
{
	UE_LOG(LogTemp, Display, TEXT("%s Rotate me"), *GetName());
}


// Return
bool AMovingPlatform::ShouldPlatformReturn()
{

	return GetDistanceMoved() > MoveDistance;
}

float AMovingPlatform::GetDistanceMoved()
{
	return FVector::Dist(StartLocation, GetActorLocation());
}