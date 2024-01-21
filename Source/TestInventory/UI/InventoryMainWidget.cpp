// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryMainWidget.h"

#include "Kismet/GameplayStatics.h"
#include "TestInventory/Core/InventoryGameMode.h"


void UInventoryMainWidget::NativeConstruct()
{
	Super::NativeConstruct();

	AInventoryGameMode* GM = Cast<AInventoryGameMode>(UGameplayStatics::GetGameMode(this));
	if (GM && GM->InventorySystem)
	{
		InventorySystem = GM->InventorySystem;
		InventorySystem.Get()->GetInventoryUpdateDelegate().AddUObject(this, &UInventoryMainWidget::UpdateData);
		UpdateData();
	}
}

void UInventoryMainWidget::UpdateData()
{
	int32 MaxWeight{}; 
	int32 CurrentWeight{};
	InventorySystem->GetInventoryWeight(CurrentWeight,MaxWeight);

	UpdateWeight(CurrentWeight, MaxWeight);
}
