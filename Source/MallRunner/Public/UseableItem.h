// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "UseableItem.generated.h"

/**
 * 
 */
UCLASS()
class MALLRUNNER_API AUseableItem : public ABaseItem
{
	GENERATED_BODY()
	
public:
	//Events
	UFUNCTION(BlueprintImplementableEvent, Category = "Useable|Events")
	void GetStatBoost();
	UFUNCTION(BlueprintImplementableEvent, Category = "Useable|Events")
	void ThrowItem();
	UFUNCTION(BlueprintImplementableEvent, Category = "Useable|Events")
	void GetSpecialBoost();

	//Functions
	UFUNCTION(BlueprintCallable, Category = "Useable|Functions")
	void CheckCrackedStatus();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Useable|Variables")
	float statBoost;
};
