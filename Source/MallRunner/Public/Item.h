// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <string>
#include "Item.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MALLRUNNER_API UItem : public UActorComponent
{
	GENERATED_BODY()

public:
	std::string itemName;
	bool selected;

public:
	UItem();

protected:
	virtual void BeginPlay() override;
};
