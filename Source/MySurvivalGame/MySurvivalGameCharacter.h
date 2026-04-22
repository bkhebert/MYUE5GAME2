// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputAction.h"  
#include "MySurvivalGameCharacter.generated.h"


UCLASS()
class MYSURVIVALGAME_API AMySurvivalGameCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* InventoryAction;

public:
	// Sets default values for this character's properties
	AMySurvivalGameCharacter();

protected:

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> InventoryWidgetClass;
	UUserWidget* InventoryWidget;

	APlayerController* GetPlayerController;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void ToggleInventory();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
