// Fill out your copyright notice in the Description page of Project Settings.


#include "DebugInventoryWidget.h"

#include "Kismet/GameplayStatics.h"
#include "TestInventory/Core/InventoryGameMode.h"

void UDebugInventoryWidget::AddItem(FInventoryItemData Item)
{
	InventorySystem.Get()->AddItem(Item);
}

void UDebugInventoryWidget::RemoveItem(FInventoryItemData Item)
{
	InventorySystem.Get()->RemoveItem(Item);
}

void UDebugInventoryWidget::NativeConstruct()
{
	Super::NativeConstruct();

	AInventoryGameMode* GM = Cast<AInventoryGameMode>(UGameplayStatics::GetGameMode(this));
	if (GM && GM->InventorySystem)
	{
		InventorySystem = GM->InventorySystem;
	}
}
