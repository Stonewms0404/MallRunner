// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MainCharacter.generated.h"


UCLASS()
class MALLRUNNER_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	struct PlayerStats {
	public:
		PlayerStats() {
			walkSpeed = 500;
			sprintSpeed = 1000;
			crouchSpeed = 100;
			slideFriction = 1;
			slideSpeed = 1000;
			crouchedHalfHeight = 40;
			halfHeightSpeed = 1;
			isCrouching = false;
			isSliding = false;
			isSprinting = false;
			isGrounded = false;
			isSlaming = false;
			isJumping = false;
			isBashing = false;
			weight = 1;
			gravityScale = 1;
		}

		float walkSpeed, sprintSpeed, crouchSpeed, slideFriction, slideSpeed, gravityScale, crouchedHalfHeight, halfHeightSpeed;
		bool isCrouching, isSliding, isSprinting, isGrounded, isBashing, isSlaming, isJumping;
		int weight;

		float GetSlamingSpeed() const {
			return weight * gravityScale * 100;
		}
		float GetBashingSpeed() const {
			return (sprintSpeed * 15) / weight;
		}
	};

	// Events
	UFUNCTION(BlueprintImplementableEvent, Category = "Player Movement|Events")
	void OnCrouchChanged(const bool Crouching);
	UFUNCTION(BlueprintImplementableEvent, Category = "Player Movement|Events")
	void OnPlayerSlide(const float SlideSpeed, const float CrouchSpeed);
	UFUNCTION(BlueprintImplementableEvent, Category = "Player Movement|Events")
	void OnCancelSlide(const float Speed);

	// Sets default values for this character's properties
	UCharacterMovementComponent* charMoveComp;
	PlayerStats* stats;

	// Constructor
	AMainCharacter();

	// Methods
	void ChangeMoveSpeed(float);
	void ChangeCrouchSpeed(float);
	void SetBaseVariables(PlayerStats*);
	void SetCrouching(bool);
	void Bash();
	void Slam();

	// Static Methods
	static float VectorToFloat(FVector vec) {
		return sqrtf(powf(vec.X, 2) + powf(vec.Y, 2));
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
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
