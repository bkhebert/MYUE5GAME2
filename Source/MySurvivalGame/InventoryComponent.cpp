// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "Engine/Engine.h" 

// Sets default values
AInventoryComponent::AInventoryComponent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	TestFunction();
}

// Called every frame
void AInventoryComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInventoryComponent::TestFunction()
{
	// This will print a message to the screen and to the output log
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("C++ Inventory Component is WORKING!"));

	// This also prints to the output log (visible in the "Output Log" window in Unreal)
	UE_LOG(LogTemp, Warning, TEXT("TestFunction was called successfully!"));
}