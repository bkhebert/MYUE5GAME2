// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryGridWidget.generated.h"


class UCanvasPanel;
class UBorder;
/**
 * 
 */
UCLASS()
class MYSURVIVALGAME_API UInventoryGridWidget : public UUserWidget
{
	GENERATED_BODY()
	
public: 

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = "UI")
    UCanvasPanel* Canvas;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = "UI")
    UBorder* GridBorder;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = "UI")
	UCanvasPanel* GridCanvasPanel;

};
