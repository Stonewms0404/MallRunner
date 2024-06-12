// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseNPC.h"
#include <PedestrianController.h>
#include "Pedestrian.generated.h"

/**
 * 
 */
UCLASS()
class MALLRUNNER_API APedestrian : public ABaseNPC
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, Category = "NPC|Pedestrian|Variables")
	EPedestrianState state;

	UPROPERTY(BlueprintReadWrite, Category = "NPC|Pedestrian|Variables")
	FVector randomNPCLocation;

	UFUNCTION(BlueprintImplementableEvent, Category = "Player Movement|Events")
	void GetRandomNPCLocation();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	void GetPatrolLocation();

private:
	APedestrianController* controller;
	float speed;

	float GetRandomSpeed();
};
