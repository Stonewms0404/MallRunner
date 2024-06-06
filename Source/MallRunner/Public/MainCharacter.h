// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include <UseableItem.h>
#include <CollectibleItem.h>
#include "MainCharacter.generated.h"

USTRUCT(BlueprintType)
struct FPlayerStats {
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category = "Player Stats|Items", meta = (ToolTip = "The first item"))
		AUseableItem* item1;
	UPROPERTY(BlueprintReadWrite, Category = "Player Stats|Items", meta = (ToolTip = "The second item"))
		AUseableItem* item2;
	UPROPERTY(BlueprintReadWrite, Category = "Player Stats|Collectibles", meta = (ToolTip = "The array of collectibles"))
		TArray<ACollectibleItem*> collectibles;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats|Variables", meta = (ToolTip = "MaxWalkSpeed of the Character Movement Component for sprinting"))
		float sprintSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats|Variables", meta = (ToolTip = "MaxWalkSpeed of the Character Movement Component for walking"))
		float walkSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats|Variables", meta = (ToolTip = "MaxWalkSpeed of the Character Movement Component for crouching"))
		float crouchSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats|Variables", meta = (ToolTip = "MaxWalkSpeed of the Character Movement Component for the initial slide speed"))
		float slideSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats|Variables", meta = (ToolTip = "MaxAcceleration of the Character Movement Component\n  The player will change it's velocity every second by this value"))
		float accelerationSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats|Variables", meta = (ToolTip = "GroundFriction of the Character Movement Component\n  The player will use this friction on the ground to move\n    Max of 8"))
		float traction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats|Variables", meta = (ToolTip = "BrakingFriction of the Character Movement Component\n  The player will use this friction on the ground to move\n    Max of 1"))
		float handling;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats|Variables", meta = (ToolTip = "The length of time the player is allowed to wall run"))
		float wallrunTime;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats|Variables", meta = (ToolTip = "The length of time between the player bashing"))
		float BashTime;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats|Variables", meta = (ToolTip = "The Speed the player runs on a wall"))
		float wallrunSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats|Variables", meta = (ToolTip = "Normal walk height of the player" ))
		float normalHeight;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats|Variables", meta = (ToolTip = "Crouched walk height of the player"))
		float crouchHeight;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats|Variables", meta = (ToolTip = "The initial velocity for the player's jump"))
		float jumpHeight;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats|Variables", meta = (ToolTip = "The scale of gravity that the player will fall"))
		float gravity;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats|Variables", meta = (ToolTip = "The player's weight and how easily it is for a the player to break \"Breakable\" Objects"))
		int weight;

	FPlayerStats() {
		item1 = nullptr;
		item2 = nullptr;
	}
};

UENUM(BlueprintType, meta = (ToolTip = "The type of player"))
enum class EPlayerType : uint8 {
	VE_Speed = 0			UMETA(DisplayName = "Speed"),
	VE_WallRunner = 1		UMETA(DisplayName = "WallRunner"),
	VE_Tank = 2				UMETA(DisplayName = "Tank"),
	VE_Clepto = 3			UMETA(DisplayName = "Clepto"),
	VE_Stealth = 4			UMETA(DisplayName = "Stealth")
};

UCLASS()
class MALLRUNNER_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Events
	UFUNCTION(BlueprintImplementableEvent, Category = "Player Movement|Events")
		void OnAccelerate(const float targetSpeed);
	UFUNCTION(BlueprintImplementableEvent, Category = "Player Movement|Events")
		void OnCrouch(const bool Crouching, const float normalHeight, const float crouchHeight, const float sprintSpeed, const float crouchSpeed);
	UFUNCTION(BlueprintImplementableEvent, Category = "Player Movement|Events")
		void OnSlide(const float normalHeight, const float crouchHeight, const float slideSpeed, const float crouchSpeed);
	UFUNCTION(BlueprintImplementableEvent, Category = "Player Movement|Events")
		void EndSlide();
	UFUNCTION(BlueprintImplementableEvent, Category = "Player Movement|Events")
		void WallJump();
	UFUNCTION(BlueprintImplementableEvent, Category = "Player Movement|Events")
		void OnStartBash(float BashSpeed, FVector ForwardVector);
	UFUNCTION(BlueprintImplementableEvent, Category = "Player Movement|Events")
		void OnEndGame(bool hasWon);

	//Blueprint Methods
	UFUNCTION(BlueprintCallable, Category = "Player Stats|Events")
		void ChangeWeight(int addedWeight);
	UFUNCTION(BlueprintCallable, Category = "Player Movement|Events")
		void OnEndBash();
	UFUNCTION(BlueprintCallable, Category = "Player Overlap|Events")
		void AddItem(AUseableItem* item);
	UFUNCTION(BlueprintCallable, Category = "Player Overlap|Events")
		void GotCaught();
	UFUNCTION(BlueprintCallable, Category = "Player Overlap|Events")
		void AddCollectible(ACollectibleItem* item);

	//Current Player Stats
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats|Variables", meta = (ToolTip = "The current stats of the player"))
		FPlayerStats stats;
	FPlayerStats* statsptr;

	//Componenets
	UCharacterMovementComponent* charMoveComp;

	void InitializeStats(FPlayerStats* newStats);


	// Static Methods
	static float VectorToFloat(FVector vec) {
		return sqrtf(powf(abs(vec.X), 2) + powf(abs(vec.Y), 2));
	}
	static float Lerp(float a, float b, float t) {
		if (a < b)
			return b + (a - b) * t;
		return  a + (b - a) * t;
	}
	static float SlowToSpeed(float a, float amount) {
		a -= amount;
		return a;
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Constructor
	AMainCharacter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};