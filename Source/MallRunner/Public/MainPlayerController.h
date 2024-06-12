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
	GENERATED_BODY()

public:

	//The Input Action for Moving.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Character Movement", meta = (ToolTip = "Move Input Action"))
	UInputAction* ActionMove = nullptr;

	//The Input Action for Looking.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Character Movement", meta = (ToolTip = "Look Input Action"))
	UInputAction* ActionLook = nullptr;

	//The Input Action for Jumping.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Character Movement", meta = (ToolTip = "Jump Input Action"))
	UInputAction* ActionJump = nullptr;

	//The Input Action for Crouching.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Character Movement", meta = (ToolTip = "Toggle Crouch Input Action"))
	UInputAction* ActionCrouch = nullptr;

	//The Input Action for Sprinting.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Character Movement", meta = (ToolTip = "Toggle Walk Input Action"))
	UInputAction* ActionWalk = nullptr;

	//The Input Action for Bashing.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Character Movement", meta = (ToolTip = "Bash Input Action"))
	UInputAction* ActionBash = nullptr;

	//The Input Action for Bashing.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Character Movement", meta = (ToolTip = "FreeLook Input Action"))
	UInputAction* ActionFreeLook = nullptr;

	//The Input Action for Canceling/Pausing.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Character Movement", meta = (ToolTip = "Cancel Input Action"))
	UInputAction* ActionCancel = nullptr;

	//The Input Mapping Context to use.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Character Movement", meta = (ToolTip = "The Input Mapping Context"))
	TObjectPtr<UInputMappingContext> InputMappingContext = nullptr;


	//Used to store a reference to the pawn we are controlling.
	AMainCharacter* PlayerCharacter = nullptr;
protected:
	UPROPERTY(BlueprintReadOnly, Category = "PlayerMovement|Variables")
	FVector forward;
	UPROPERTY(BlueprintReadWrite, Category = "PlayerMovement|Variables")
	bool isMoving;
	UPROPERTY(BlueprintReadWrite, Category = "PlayerMovement|Variables")
	bool isWallRunning;

	//Variables to change in the inspector
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats|Variables", meta = (ToolTip = "The stats for the Speed Character"))
		FPlayerStats SpeedStats;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats|Variables", meta = (ToolTip = "The stats for the Wall Runner Character"))
		FPlayerStats WallRunnerStats;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats|Variables", meta = (ToolTip = "The stats for the Tank Character"))
		FPlayerStats TankStats;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats|Variables", meta = (ToolTip = "The stats for the Clepto Character"))
		FPlayerStats CleptoStats;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats|Variables", meta = (ToolTip = "The stats for the Stealth Character"))
		FPlayerStats StealthStats;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats|Variables", meta = (ToolTip = "The type of character"))
	EPlayerType playerType = EPlayerType::VE_Speed;

	//Movement handles
	void HandleMove(const FInputActionValue& InputActionValue);
	void StopMoving(const FInputActionValue& _);
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


	bool freeLooking = false, isPaused = false, hasBashed = false;


};