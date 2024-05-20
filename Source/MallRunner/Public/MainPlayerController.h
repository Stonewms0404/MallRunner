// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include <EnhancedInputComponent.h>
#include "GameFramework/CharacterMovementComponent.h"
#include "MainCharacter.h"
#include <EnhancedPlayerInput.h>
#include "MainPlayerController.generated.h"

/**
 *
 */
UCLASS()
class MALLRUNNER_API AMainPlayerController : public APlayerController
{
public:

	//The Input Action for Moving.
	UPROPERTY(EditDefaultsOnly,
		BlueprintReadOnly,
		Category = "Player Movement|Character Movement")
	UInputAction* ActionMove = nullptr;

	//The Input Action for Looking.
	UPROPERTY(EditDefaultsOnly,
		BlueprintReadOnly,
		Category = "Player Movement|Character Movement")
	UInputAction* ActionLook = nullptr;

	//The Input Action for Jumping.
	UPROPERTY(EditDefaultsOnly,
		BlueprintReadOnly,
		Category = "Player Movement|Character Movement")
	UInputAction* ActionJump = nullptr;

	//The Input Action for Crouching.
	UPROPERTY(EditDefaultsOnly,
		BlueprintReadOnly,
		Category = "Player Movement|Character Movement")
	UInputAction* ActionCrouch = nullptr;

	//The Input Action for Sprinting.
	UPROPERTY(EditDefaultsOnly,
		BlueprintReadOnly,
		Category = "Player Movement|Character Movement")
	UInputAction* ActionSprint = nullptr;

	//The Input Action for Bashing.
	UPROPERTY(EditDefaultsOnly,
		BlueprintReadOnly,
		Category = "Player Movement|Character Movement")
	UInputAction* ActionBash = nullptr;

	//The Input Action for Bashing.
	UPROPERTY(EditDefaultsOnly,
		BlueprintReadOnly,
		Category = "Player Movement|Character Movement")
	UInputAction* ActionSlam = nullptr;

	//The Input Action for Canceling/Pausing.
	UPROPERTY(EditDefaultsOnly,
		BlueprintReadOnly,
		Category = "Player Movement|Character Movement")
	UInputAction* ActionCancel = nullptr;

	//The Input Mapping Context to use.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Character Movement")
	TObjectPtr<UInputMappingContext> InputMappingContext = nullptr;

protected:
	//Variables to change in the inspector
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Stats")
	float baseSpeed = 450;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Stats")
	float baseSlide = 1400;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Stats")
	float baseSlideFriction = 10;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Stats")
	float baseSprint = 1200;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Stats")
	float baseCrouchSpeed = 180;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Stats")
	float baseJumpHeight = 1100;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Stats")
	float baseBreakingFriction = 1;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Stats")
	float baseAirControl = 0.75;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Stats")
	float baseMaxAcceleration = 1500;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Stats")
	float baseGravityScale = 3;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Stats")
	float baseCrouchHeight = 32;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Stats")
	float baseCrouchHeightSpeed = 3;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Stats")
	int baseWeight = 5;

	AMainCharacter::PlayerStats* controllerStats;

	//Booleans that might be useful to use in Blueprints
	bool bIsCrouching = false;
	bool bIsSprinting = false;
	bool bIsMenuOpen = false;
	bool bIsJumping = false;
	bool bIsSliding = false;

	//Movement handles
	void HandleMove(const FInputActionValue& InputActionValue);
	void HandleLook(const FInputActionValue& InputActionValue);
	void HandleJump();
	void HandleCrouch();
	void HandleSprint();
	void HandleBash();
	void HandleSlam();
	void HandleCancel();


	virtual void OnPossess(APawn* aPawn) override;
	virtual void OnUnPossess() override;

private:

	void SetPlayerControllerSettings();

	//Used to store a reference to InputComponent cast to an EnhancedInputComponent.
	UPROPERTY()
	UEnhancedInputComponent* EnhancedInputComponent = nullptr;

	//Used to store a reference to the pawn we are controlling.
	UPROPERTY()
	AMainCharacter* PlayerCharacter = nullptr;


	GENERATED_BODY()
};
