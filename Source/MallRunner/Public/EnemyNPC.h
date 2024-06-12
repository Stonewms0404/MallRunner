// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseNPC.h"
#include "EnemyController.h"
#include "MainPlayerController.h"
#include "EnemyNPC.generated.h"


UCLASS()
class MALLRUNNER_API AEnemyNPC : public ABaseNPC
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, Category = "NPC|Enemy|Variables")
	FVector lastPlayerLocation;

	UPROPERTY(BlueprintReadWrite, Category = "NPC|Enemy|Variables")
	bool canSeePlayer;
	UPROPERTY(BlueprintReadWrite, Category = "NPC|Enemy|Variables")
	bool isFrozen;
	UPROPERTY(BlueprintReadWrite, Category = "NPC|Enemy|Variables")
	bool inCrowd;


	UPROPERTY(BlueprintReadWrite, Category = "NPC|Enemy|Variables")
	AMainPlayerController* playerController;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(BlueprintReadWrite, Category = "NPC|Enemy|Variables")
	EEnemyState state;

	void StartSearchTimer();
	bool UseSearchTimer(float);
	void GetPatrolLocation();

private:
	bool searchTimerStarted, isRunning;
	float searchTimer, searchTimerLength;

	AEnemyController* controller;
};
