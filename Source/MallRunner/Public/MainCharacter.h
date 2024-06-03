// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include <Item.h>
#include "MainCharacter.generated.h"


UCLASS()
class MALLRUNNER_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	struct PlayerStats {
	public:
		UItem* item1;
		UItem* item2;
		float sprintSpeed, walkSpeed, crouchSpeed, slideSpeed, accelerationSpeed,
			traction, handling, bashTime,
			normalHeight, crouchHeight, jumpHeight, gravity;
		int weight;

		PlayerStats() {
			item1 = nullptr;
			item2 = nullptr;
		}
	};

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
	void OnStartBash(float BashSpeed, FVector ForwardVector);
	UFUNCTION(BlueprintImplementableEvent, Category = "Player Stats|Events")
	void OnChangeWeight(float BashSpeed, FVector ForwardVector);

	//Blueprint Methods
	UFUNCTION(BlueprintCallable, Category = "Player Movement|Events")
	void OnEndBash();
	UFUNCTION(BlueprintCallable, Category = "Player Overlap|Events")
	void AddItem(UItem* item);
	UFUNCTION(BlueprintCallable, Category = "Player Overlap|Events")
	void GotCaught();
	UFUNCTION(BlueprintCallable, Category = "Player Overlap|Events")
	void AddCollectible();

	PlayerStats* stats = nullptr;
	UCharacterMovementComponent* charMoveComp;

	void InitializeStats(PlayerStats* newStats);


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