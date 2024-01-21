// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySystem.h"

void UInventorySystem::SetupInventoryMaxSize(int32 Size)
{
	InventoryMaxSize = Size;
	InventoryUpdateDelegate.Broadcast();
}

void UInventorySystem::GetInventoryWeight(int32& CurrentWeight, int32& MaxWeight) const
{
	MaxWeight = InventoryMaxSize;
	CurrentWeight = InventorySize;
}

void UInventorySystem::AddItem(const FInventoryItemData& NewItem)
{
	if(InventoryMaxSize >= (InventorySize + NewItem.Weight))
	{
		ItemsInInventory.Add(NewItem);
		InventorySize += NewItem.Weight;
	}
	else
	{
		//Call Error
	}

	InventoryUpdateDelegate.Broadcast();
}

void UInventorySystem::RemoveItem(const FInventoryItemData& ItemToRemove)
{
	if(ItemsInInventory.Num() > 0)
	{
		const int32 Index = ItemsInInventory.Find(ItemToRemove);
		if(Index != INDEX_NONE)
		{
			ItemsInInventory.RemoveAt(Index);
		}
		else
		{
			//FInventoryItemData Item = *ItemsInInventory.FindByPredicate([&ItemToRemove](FInventoryItemData& Element) { return Element.ItemType == ItemToRemove.ItemType; });
			const int32 NextIndex = ItemsInInventory.FindLastByPredicate([&ItemToRemove](const FInventoryItemData& Element) { return Element.ItemType == ItemToRemove.ItemType; });
			if(NextIndex != INDEX_NONE)
			{
				ItemsInInventory.RemoveAt(NextIndex);
			}
			else
			{
				// Error no item in category
			}
		}
	}
	else
	{
		//Call Error	
	}

	UpdateWeight();
	
	InventoryUpdateDelegate.Broadcast();
}

TArray<FInventoryItemData> UInventorySystem::GetItemsByType(EItemType Type)
{
	TArray<FInventoryItemData> TempArray = {};

	for (FInventoryItemData Item : ItemsInInventory)
	{
		if(Item.ItemType == Type )
		{
			TempArray.Add(Item);
		}
	}
	
	return TempArray; 
}

void UInventorySystem::UpdateWeight()
{
	InventorySize = 0;
	for (FInventoryItemData Item : ItemsInInventory)
	{
		InventorySize += Item.Weight;
	}
}
