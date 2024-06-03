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
		Category = "Player Movement|Character Movement",
		meta = (ToolTip = "Move Input Action"))
	UInputAction* ActionMove = nullptr;

	//The Input Action for Looking.
	UPROPERTY(EditDefaultsOnly,
		BlueprintReadOnly,
		Category = "Player Movement|Character Movement",
		meta = (ToolTip = "Look Input Action"))
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
	UInputAction* ActionWalk = nullptr;

	//The Input Action for Bashing.
	UPROPERTY(EditDefaultsOnly,
		BlueprintReadOnly,
		Category = "Player Movement|Character Movement")
	UInputAction* ActionBash = nullptr;

	//The Input Action for Bashing.
	UPROPERTY(EditDefaultsOnly,
		BlueprintReadOnly,
		Category = "Player Movement|Character Movement")
	UInputAction* ActionFreeLook = nullptr;

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
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Stats|SpeedCharacter")
	float baseSprintSpeed = 1000;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Stats|SpeedCharacter")
	float baseWalkSpeed = 450;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Stats|SpeedCharacter")
	float baseCrouchSpeed = 200;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Stats|SpeedCharacter")
	float baseSlideSpeed = 1200;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Stats|SpeedCharacter")
	float baseTraction = .75;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Stats|SpeedCharacter")
	float baseHandling = .5;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Stats|SpeedCharacter")
	float baseAccelerationSpeed = 450;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Stats|SpeedCharacter")
	float baseNormalHeight = 80;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Stats|SpeedCharacter")
	float baseCrouchHeight = 40;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Stats|SpeedCharacter")
	float baseJumpVelocity = 1000;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Stats|SpeedCharacter")
	float baseGravity = 3;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Stats|SpeedCharacter")
	int baseWeight = 80;


	//Movement handles
	void HandleMove(const FInputActionValue& InputActionValue);
	void HandleLook(const FInputActionValue& InputActionValue);
	void StartJump();
	void EndJump();
	void StartCrouch();
	void EndCrouch();
	void StartWalk();
	void EndWalk();
	void HandleBash();
	void StartFreeLook();
	void EndFreeLook();
	void HandleCancel();

	virtual void OnPossess(APawn* aPawn) override;
	virtual void OnUnPossess() override;

private:
	//Used to store a reference to InputComponent cast to an EnhancedInputComponent.
	UPROPERTY()
	UEnhancedInputComponent* EnhancedInputComponent = nullptr;

	//Used to store a reference to the pawn we are controlling.
	UPROPERTY()
	AMainCharacter* PlayerCharacter = nullptr;

	bool freeLooking = false, isPaused = false;
	FVector forward;

	GENERATED_BODY()
};