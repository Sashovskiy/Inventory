// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TestInventory/UI/InventoryMainWidget.h"
#include "InventoryHUD.generated.h"

/**
 * 
 */
UCLASS()
class TESTINVENTORY_API AInventoryHUD : public AHUD
{
	GENERATED_BODY()

	
public:


	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UInventoryMainWidget> InventoryMainWidgetClass;

private:

	UPROPERTY()
	UInventoryMainWidget* InventoryMainWidget = nullptr;
};
