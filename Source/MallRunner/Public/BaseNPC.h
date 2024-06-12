// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "BaseNPC.generated.h"


UENUM(BlueprintType)
enum class EEnemyState : uint8 {
	VE_Idle = 0			UMETA(DisplayName = "Idle"),
	VE_Patrolling = 1	UMETA(DisplayName = "Patrolling"),
	VE_Searching = 2	UMETA(DisplayName = "Searching"),
	VE_Chasing = 3		UMETA(DisplayName = "Chasing")
};
UENUM(BlueprintType)
enum class EPedestrianState : uint8 {
	VE_Idle = 0			UMETA(DisplayName = "Idle"),
	VE_Patrolling = 1	UMETA(DisplayName = "Patrolling")
};

UCLASS()
class MALLRUNNER_API ABaseNPC : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseNPC();

	void InitializeStats(FNPCStruct);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "NPC|Variables")
	FNPCStruct stats;


	UCharacterMovementComponent* charMoveComp;
	UCapsuleComponent* capsule;

	virtual void StartIdleTimer();
	virtual bool UseIdleTimer(float);
	virtual void CheckPatrolLocation();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	FVector patrolLocation;
	bool atPatrolLocation;

	bool idleTimerStarted;
	float idleTimer, idleTimerLength;
public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
