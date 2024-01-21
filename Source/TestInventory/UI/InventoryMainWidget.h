// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TestInventory/Core/Inventory/InventorySystem.h"
#include "InventoryMainWidget.generated.h"

/**
 * 
 */
UCLASS()
class TESTINVENTORY_API UInventoryMainWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	void UpdateData();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateWeight(const int32& CurrentWeight, const int32& MaxWeight);
private:
	
	TWeakObjectPtr<UInventorySystem> InventorySystem{nullptr};
};
