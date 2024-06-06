// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseItem.generated.h"

UENUM(BlueprintType)
enum class ETypeOfItem : uint8 {
	VE_StatBoost = 0		UMETA(DisplayName = "StatBoost"),
	VE_SpecialBoost = 1		UMETA(DisplayName = "SpecialBoost"),
	VE_Throwable = 2		UMETA(DisplayName = "Throwable"),
	VE_Collectible = 3		UMETA(DisplayName = "Collectible")
};

UCLASS()
class MALLRUNNER_API ABaseItem : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(BlueprintReadWrite, Category = "Item|Variables")
	bool selected = false;
	UPROPERTY(BlueprintReadWrite, Category = "Item|Variables")
	bool isCracked = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item|Variables")
	ETypeOfItem itemType = ETypeOfItem::VE_StatBoost;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item|Variables")
	FString name = "";

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Sets default values for this actor's properties
	ABaseItem();

};
