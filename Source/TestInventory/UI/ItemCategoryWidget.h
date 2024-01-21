// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/TileView.h"
#include "TestInventory/Core/Inventory/InventorySystem.h"
#include "TestInventory/Data/InventoryData.h"
#include "ItemCategoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class TESTINVENTORY_API UItemCategoryWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn))
	EItemType CategoryType = EItemType::None;

	UFUNCTION(BlueprintCallable)
	void SetUpCategoryWidget(EItemType Type);

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTileView* TileItemList{};
	
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* NoItemTextBlock{};

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateCategoryWeight(const int32& Weight);
	
protected:
	virtual void NativeConstruct() override;

	void UpdateData();

private:

	int32 CategoryWeight = 0;
	
	TWeakObjectPtr<UInventorySystem> InventorySystem{nullptr};
};

UCLASS(Blueprintable)
class UItemListData : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FInventoryItemData Data;
};
