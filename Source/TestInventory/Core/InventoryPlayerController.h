// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InventoryPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TESTINVENTORY_API AInventoryPlayerController : public APlayerController
{
	GENERATED_BODY()


	virtual void BeginPlay() override;
};
