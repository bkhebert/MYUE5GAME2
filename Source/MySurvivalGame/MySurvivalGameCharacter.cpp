// Fill out your copyright notice in the Description page of Project Settings.


#include "MySurvivalGameCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Controller.h"
#include "InputActionValue.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"

// Sets default values
AMySurvivalGameCharacter::AMySurvivalGameCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMySurvivalGameCharacter::BeginPlay()
{  
	Super::BeginPlay(); 
	GetPlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (GetPlayerController) {
		if (InventoryWidgetClass) {
			InventoryWidget = CreateWidget(GetWorld(), InventoryWidgetClass);
			InventoryWidget->SetOwningPlayer(GetPlayerController);
		}
	}
}

void AMySurvivalGameCharacter::ToggleInventory()
{
	if (InventoryWidget->IsInViewport()) {
		InventoryWidget->RemoveFromParent();
		GetPlayerController->SetShowMouseCursor(false);
		GetPlayerController->SetInputMode(FInputModeGameOnly());
	}
	else {
		InventoryWidget->AddToViewport();
		GetPlayerController->SetShowMouseCursor(true);
		GetPlayerController->SetInputMode(FInputModeGameAndUI());
	}
}

// Called every frame
void AMySurvivalGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMySurvivalGameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		EnhancedInputComponent->BindAction(InventoryAction, ETriggerEvent::Started, this, &AMySurvivalGameCharacter::ToggleInventory);
	}
}

