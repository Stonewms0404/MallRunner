// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseNPC.generated.h"

USTRUCT(BlueprintType)
struct FNPCStruct {
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Variables")
	float sprintSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Variables")
	float walkSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Variables")
	float searchRadius;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Variables")
	float forgetTimer;
};

UENUM(BlueprintType)
enum class ENPCState : uint8 {
	VE_Idle = 0			UMETA(DisplayName = "Idle"),
	VE_Patrolling = 1	UMETA(DisplayName = "Patrolling"),
	VE_Searching = 2	UMETA(DisplayName = "Searching"),
	VE_Chasing = 3		UMETA(DisplayName = "Chasing")
};

UCLASS()
class MALLRUNNER_API ABaseNPC : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseNPC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
