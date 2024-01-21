// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryHUD.h"

void AInventoryHUD::BeginPlay()
{
	Super::BeginPlay();

	if(!IsValid(InventoryMainWidget))
	{
		InventoryMainWidget = CreateWidget<UInventoryMainWidget>(GetGameInstance(),InventoryMainWidgetClass,TEXT("MainWidget"));
		InventoryMainWidget->AddToViewport(0);
	}
}
