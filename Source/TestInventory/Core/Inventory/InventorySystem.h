// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TestInventory/Data/InventoryData.h"
#include "UObject/Object.h"
#include "InventorySystem.generated.h"


DECLARE_EVENT(UInventory, FInventoryUpdateDelegate)

UCLASS()
class TESTINVENTORY_API UInventorySystem : public UObject
{
	GENERATED_BODY()

public:

	void SetupInventoryMaxSize(int32 Size);
	FInventoryUpdateDelegate& GetInventoryUpdateDelegate(){return InventoryUpdateDelegate;};

	void GetInventoryWeight(int32& CurrentWeight, int32& MaxWeight) const;
	
	void AddItem(const FInventoryItemData& NewItem);
	void RemoveItem(const FInventoryItemData& ItemToRemove);
	
	
	TArray<FInventoryItemData> GetItemsByType(EItemType Type);
protected:

	void UpdateWeight();

private:

	FInventoryUpdateDelegate InventoryUpdateDelegate;

	int32 InventorySize = 0;
	int32 InventoryMaxSize = 0;
	TArray<FInventoryItemData> ItemsInInventory;
};
