#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "InventoryData.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8
{
	None,
	Weapon,
	Armor,
	Scrolls,
	Food,
	
};

USTRUCT(BlueprintType)
struct FInventoryItemData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Name{};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture* Icon{};
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Weight = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EItemType ItemType = EItemType::None;

	bool operator==(const FInventoryItemData& Other) const
	{
		return Name.EqualTo(Other.Name);
	}
};

USTRUCT(BlueprintType)
struct FItemTypeData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EItemType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor TypeColor;
};
