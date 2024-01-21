// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TestInventory/Core/Inventory/InventorySystem.h"
#include "TestInventory/Data/InventoryData.h"
#include "DebugInventoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class TESTINVENTORY_API UDebugInventoryWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void AddItem(FInventoryItemData Item);
	
	UFUNCTION(BlueprintCallable)
	void RemoveItem(FInventoryItemData Item);

protected:

	virtual void NativeConstruct() override;

private:

	TWeakObjectPtr<UInventorySystem> InventorySystem{nullptr};
};
