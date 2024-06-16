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
	
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	APedestrianController* controller;
	float speed;
};
