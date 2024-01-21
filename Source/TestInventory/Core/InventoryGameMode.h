// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Inventory/InventorySystem.h"
#include "InventoryGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TESTINVENTORY_API AInventoryGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MaxInventorySize;
	
	UPROPERTY()
	UInventorySystem* InventorySystem = nullptr;
};
