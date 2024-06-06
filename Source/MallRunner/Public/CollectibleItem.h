// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "CollectibleItem.generated.h"

UENUM(BlueprintType)
enum class ECollectibleType : uint8 {
	VE_Minor = 0		UMETA(DisplayName = "Minor"),
	VE_Major = 1		UMETA(DisplayName = "Major"),
	VE_Unique = 2		UMETA(DisplayName = "Unique")
};

/**
 * 
 */
UCLASS()
class MALLRUNNER_API ACollectibleItem : public ABaseItem
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Collectible|Variables")
	ECollectibleType collectibleType = ECollectibleType::VE_Minor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Collectible|Variables")
	int value;
};
