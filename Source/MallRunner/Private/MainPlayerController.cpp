// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerController.h"
#include <EnhancedInputSubsystems.h>


void AMainPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	//Store a reference to the Player's Pawn
	PlayerCharacter = Cast<AMainCharacter>(aPawn);
	checkf(PlayerCharacter, TEXT("AMainPlayerController derived classes should only possess AMainCharacter derived pawns"));

	//Get a reference to the EnhancedInputComponent
	EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	checkf(EnhancedInputComponent, TEXT("Unable to get reference to the EnhancedInputComponent."));

	//Get the local player subsystem.
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	checkf(InputSubsystem, TEXT("Unable to get reference to the UEnhancedInputLocalPlayerSubsystem."));


	//Wipe existing mappings, and add our mapping.
	checkf(InputMappingContext, TEXT("InputMappingContext was not specified."));
	InputSubsystem->ClearAllMappings();
	InputSubsystem->AddMappingContext(InputMappingContext, 0);

	if (ActionMove) {
		EnhancedInputComponent->BindAction(ActionMove, ETriggerEvent::Triggered,
			this, &AMainPlayerController::HandleMove);
	}

	if (ActionLook) {
		EnhancedInputComponent->BindAction(ActionLook, ETriggerEvent::Triggered,
			this, &AMainPlayerController::HandleLook);
	}

	if (ActionJump) {
		EnhancedInputComponent->BindAction(ActionJump, ETriggerEvent::Triggered,
			this, &AMainPlayerController::HandleJump);
	}

	if (ActionCrouch) {
		EnhancedInputComponent->BindAction(ActionCrouch, ETriggerEvent::Triggered,
			this, &AMainPlayerController::HandleCrouch);
	}

	if (ActionSprint) {
		EnhancedInputComponent->BindAction(ActionSprint, ETriggerEvent::Triggered,
			this, &AMainPlayerController::HandleSprint);
	}

	if (ActionBash) {
		EnhancedInputComponent->BindAction(ActionBash, ETriggerEvent::Triggered,
			this, &AMainPlayerController::HandleBash);
	}

	if (ActionCancel) {
		EnhancedInputComponent->BindAction(ActionCancel, ETriggerEvent::Triggered,
			this, &AMainPlayerController::HandleCancel);
	}
}

void AMainPlayerController::OnUnPossess()
{
	EnhancedInputComponent->ClearActionBindings();

	Super::OnUnPossess();
}

void AMainPlayerController::HandleMove(const FInputActionValue & InputActionValue)
{
	const FVector2D MovementVector = InputActionValue.Get<FVector2D>();

	if (bIsSprinting) {
		PlayerCharacter->AddMovementInput(PlayerCharacter->GetActorForwardVector(), Speed * SprintMultiplier * MovementVector.Y);
		PlayerCharacter->AddMovementInput(PlayerCharacter->GetActorRightVector(), MovementVector.X);
	}
	else {
		PlayerCharacter->AddMovementInput(PlayerCharacter->GetActorForwardVector(), Speed * MovementVector.Y);
		PlayerCharacter->AddMovementInput(PlayerCharacter->GetActorRightVector(), MovementVector.X);
	}
}

void AMainPlayerController::HandleLook(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

	AddYawInput(LookAxisVector.X);
	AddPitchInput(LookAxisVector.Y);
}

void AMainPlayerController::HandleJump()
{
	PlayerCharacter->UnCrouch();
	PlayerCharacter->Jump();
}

void AMainPlayerController::HandleCrouch()
{
	if (bIsCrouching) {
		PlayerCharacter->UnCrouch();
	}
	else {
		PlayerCharacter->Crouch();
	}
	bIsCrouching = !bIsCrouching;
}

void AMainPlayerController::HandleSprint()
{
	bIsSprinting = !bIsSprinting;
}

void AMainPlayerController::HandleBash()
{
}

void AMainPlayerController::HandleCancel()
{
	bIsMenuOpen = !bIsMenuOpen;
}
