// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "BaseNPC.generated.h"


USTRUCT(BlueprintType)
struct FNPCStruct {
	GENERATED_BODY()

public:
	FNPCStruct() {}
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Stats|Variables", meta = (ToolTip = "MaxWalkSpeed of the Character Movement Component for sprinting"))
	float sprintSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Stats|Variables", meta = (ToolTip = "MaxWalkSpeed of the Character Movement Component for walking"))
	float walkSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Stats|Variables", meta = (ToolTip = "MaxAcceleration of the Character Movement Component\n  The player will change it's velocity every second by this value"))
	float accelerationSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Stats|Variables", meta = (ToolTip = "GroundFriction of the Character Movement Component\n  The player will use this friction on the ground to move\n    Max of 8"))
	float traction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Stats|Variables", meta = (ToolTip = "BrakingFriction of the Character Movement Component\n  The player will use this friction on the ground to move\n    Max of 1"))
	float handling;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Stats|Variables", meta = (ToolTip = "Normal walk height of the player"))
	float normalHeight;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Stats|Variables", meta = (ToolTip = "Normal walk height of the player"))
	float forgetTimer;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Stats|Variables", meta = (ToolTip = "The scale of gravity that the player will fall"))
	float gravity;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Stats|Variables", meta = (ToolTip = "The player's weight and how easily it is for a the player to break \"Breakable\" Objects"))
	int weight;

	UPROPERTY(BlueprintReadOnly, Category = "NPC|Variables")
	bool canAlert;
	UPROPERTY(BlueprintReadOnly, Category = "NPC|Variables")
	bool canCatch;
};

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
