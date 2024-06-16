// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "BehaviorTree/BehaviorTree.h"
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
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Stats|Variables", meta = (ToolTip = "Normal walk height of the character"))
	float normalHeight;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Stats|Variables", meta = (ToolTip = "The speed it takes to turn the character"))
	float TurnSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Stats|Variables", meta = (ToolTip = "Time to forget a not seen character"))
	float forgetTimer;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Stats|Variables", meta = (ToolTip = "The scale of gravity that the character will fall"))
	float gravity;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Stats|Variables", meta = (ToolTip = "The character's weight"))
	int weight;

	UPROPERTY(BlueprintReadOnly, Category = "NPC|Variables")
	bool canAlert;
	UPROPERTY(BlueprintReadOnly, Category = "NPC|Variables")
	bool canCatch;
};

UCLASS()
class MALLRUNNER_API ABaseNPC : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseNPC();

	void InitializeStats(FNPCStruct*);

	UBehaviorTree* GetBehaviorTree() const;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "NPC|Variables")
	FNPCStruct stats;
	FNPCStruct* statsptr;


	UCharacterMovementComponent* charMoveComp;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|AI")
	UBehaviorTree* Tree = nullptr;
};
