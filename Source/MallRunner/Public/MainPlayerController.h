// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include <MainCharacter.h>
#include <EnhancedInputComponent.h>
#include <EnhancedPlayerInput.h>
#include "MainPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MALLRUNNER_API AMainPlayerController : public APlayerController
{
public:
	//Variables to change in the inspector
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Stats")
	int SprintMultiplier = 1;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Stats")
	int Speed = 1;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Stats")
	int Weight = 1;

	//Booleans that might be useful to use in Blueprints
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Movement|Identifiers")
	bool bIsCrouching = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Movement|Identifiers")
	bool bIsSprinting = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Movement|Identifiers")
	bool bIsMenuOpen = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Movement|Identifiers")
	bool bIsJumping = false;

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
	
	//The Input Action for Canceling/Pausing.
	UPROPERTY(EditDefaultsOnly,
		BlueprintReadOnly,
		Category = "Player Movement|Character Movement")
	UInputAction* ActionCancel = nullptr;

	//The Input Mapping Context to use.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Movement|Character Movement")
	TObjectPtr<UInputMappingContext> InputMappingContext = nullptr;

protected:
	void HandleMove(const FInputActionValue& InputActionValue);
	void HandleLook(const FInputActionValue& InputActionValue);
	void HandleJump();
	void HandleCrouch();
	void HandleSprint();
	void HandleBash();
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


	GENERATED_BODY()
};
