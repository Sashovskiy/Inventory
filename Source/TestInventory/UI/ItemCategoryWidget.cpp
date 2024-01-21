// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemCategoryWidget.h"

#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "TestInventory/Core/InventoryGameMode.h"

void UItemCategoryWidget::SetUpCategoryWidget(EItemType Type)
{
	CategoryType = Type;
}

void UItemCategoryWidget::NativeConstruct()
{
	Super::NativeConstruct();

	AInventoryGameMode* GM = Cast<AInventoryGameMode>(UGameplayStatics::GetGameMode(this));
	if (GM && GM->InventorySystem)
	{
		InventorySystem = GM->InventorySystem;
		InventorySystem.Get()->GetInventoryUpdateDelegate().AddUObject(this, &UItemCategoryWidget::UpdateData);
	}
}

void UItemCategoryWidget::UpdateData()
{
	if(InventorySystem.IsValid())
	{
		TArray<FInventoryItemData> Data = InventorySystem.Get()->GetItemsByType(CategoryType);
		TileItemList->ClearListItems();
		CategoryWeight = 0;
		const ESlateVisibility TextVisibility = Data.IsEmpty() ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed;
		NoItemTextBlock->SetVisibility(TextVisibility);
		for(const FInventoryItemData& Item : Data)
		{
			UItemListData* ListData = NewObject<UItemListData>(this);
			ListData->Data = Item;
			CategoryWeight += Item.Weight; 
			TileItemList->AddItem(ListData);
		}

		UpdateCategoryWeight(CategoryWeight);
	}
}

