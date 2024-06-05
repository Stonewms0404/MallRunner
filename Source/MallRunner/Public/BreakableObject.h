// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "BreakableObject.generated.h"

/**
 * 
 */
UCLASS()
class MALLRUNNER_API ABreakableObject : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintImplementableEvent, Category = "Breakable|Events")
	void ChangeColor(int selection);

	UFUNCTION(BlueprintCallable, Category = "Breakable|Functions")
	void CheckWeights(int playerWeight);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Breakable|Variables")
	int weight = 1;
	UPROPERTY(BlueprintReadWrite, Category = "Breakable|Variables")
	bool canBreak;
};
