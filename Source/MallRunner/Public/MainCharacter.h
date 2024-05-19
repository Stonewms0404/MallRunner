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
	// Sets default values for this character's properties
	UCharacterMovementComponent* charMoveComp;


	struct PlayerStats {
	public:
		PlayerStats() {
			walkSpeed = 500;
			sprintSpeed = 1000;
			crouchSpeed = 100;
			slideFriction = 1;
			slideSpeed = 1000;
			isCrouching = false;
			isSliding = false;
			isSprinting = false;
			isGrounded = false;
			isBashing = false;
			isJumping = false;
			weight = 1;
			gravityScale = 1;
		}

		float walkSpeed, sprintSpeed, crouchSpeed, slideFriction, slideSpeed, gravityScale;
		bool isCrouching, isSliding, isSprinting, isGrounded, isBashing, isJumping;
		int weight;

		float GetBashingSpeed() const {
			return weight * gravityScale * 100;
		}
	};
	AMainCharacter();
	PlayerStats* stats;

	void ChangeMoveSpeed(float);
	void ChangeCrouchSpeed(float);
	void SetBaseVariables(PlayerStats*);

	static float VectorToFloat(FVector vec) {
		return sqrtf(powf(vec.X, 2) + powf(vec.Y, 2));
	}
	static float Lerp(float a, float b, float t) {
		if (a < b)
			return b + (a - b) * t;
		return  a + (b - a) * t;
	}

protected:
	void Slide();
	void Bash();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
