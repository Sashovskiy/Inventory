// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryGameMode.h"

void AInventoryGameMode::BeginPlay()
{
	Super::BeginPlay();


	if(!IsValid(InventorySystem))
	{
		InventorySystem = NewObject<UInventorySystem>(this);
		InventorySystem->SetupInventoryMaxSize(MaxInventorySize);
	}
}
