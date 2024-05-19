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

	SetPlayerControllerSettings();
	controllerStats = new AMainCharacter::PlayerStats();

	controllerStats->crouchSpeed = baseCrouchSpeed;
	controllerStats->slideSpeed = baseSlide;
	controllerStats->slideFriction = baseSlideFriction;
	controllerStats->sprintSpeed = baseSprint;
	controllerStats->walkSpeed = baseSpeed;
	controllerStats->weight = baseWeight;
	controllerStats->gravityScale = baseGravityScale;

	PlayerCharacter->SetBaseVariables(controllerStats);
}

void AMainPlayerController::OnUnPossess()
{
	EnhancedInputComponent->ClearActionBindings();

	Super::OnUnPossess();
}

void AMainPlayerController::SetPlayerControllerSettings()
{
	PlayerCharacter->charMoveComp->MaxWalkSpeed = baseSpeed;
	PlayerCharacter->charMoveComp->MaxWalkSpeedCrouched = baseCrouchSpeed;
	PlayerCharacter->charMoveComp->JumpZVelocity = baseJumpHeight;
	PlayerCharacter->charMoveComp->BrakingFriction = baseBreakingFriction;
	PlayerCharacter->charMoveComp->AirControl = baseAirControl;
	PlayerCharacter->charMoveComp->MaxAcceleration = baseMaxAcceleration;
	PlayerCharacter->charMoveComp->GravityScale = baseGravityScale;

}

void AMainPlayerController::HandleMove(const FInputActionValue & InputActionValue)
{
	const FVector2D MovementVector = InputActionValue.Get<FVector2D>();

	PlayerCharacter->AddMovementInput(PlayerCharacter->GetActorForwardVector(), MovementVector.Y);
	PlayerCharacter->AddMovementInput(PlayerCharacter->GetActorRightVector(), MovementVector.X);
}

void AMainPlayerController::HandleLook(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

	AddYawInput(LookAxisVector.X);
	AddPitchInput(LookAxisVector.Y);
}

void AMainPlayerController::HandleJump()
{
	if (PlayerCharacter->stats->isSliding)
		PlayerCharacter->charMoveComp->MaxWalkSpeed = PlayerCharacter->stats->sprintSpeed * 2;
	PlayerCharacter->stats->isJumping = false;
	PlayerCharacter->UnCrouch();
	PlayerCharacter->stats->isCrouching = false;
	PlayerCharacter->Jump();
}

void AMainPlayerController::HandleCrouch()
{
	PlayerCharacter->stats->isSprinting = false;
	if (AMainCharacter::VectorToFloat(PlayerCharacter->charMoveComp->Velocity) < PlayerCharacter->stats->walkSpeed / 2.0f) {
		if (PlayerCharacter->stats->isCrouching) {
			PlayerCharacter->ChangeMoveSpeed(PlayerCharacter->stats->walkSpeed);
			PlayerCharacter->UnCrouch();
		}
		else {
			PlayerCharacter->ChangeCrouchSpeed(PlayerCharacter->stats->crouchSpeed);
			PlayerCharacter->Crouch();
		}
	}
	else {
		if (PlayerCharacter->stats->isCrouching) {
			PlayerCharacter->ChangeMoveSpeed(PlayerCharacter->stats->walkSpeed);
			PlayerCharacter->UnCrouch();
		}
		else {
			PlayerCharacter->ChangeCrouchSpeed(PlayerCharacter->stats->slideSpeed);
			PlayerCharacter->Crouch();
		}
	}
	PlayerCharacter->stats->isCrouching = !PlayerCharacter->stats->isCrouching;
}

void AMainPlayerController::HandleSprint()
{
	PlayerCharacter->stats->isSprinting = !PlayerCharacter->stats->isSprinting;
	if (PlayerCharacter->stats->isCrouching) {
		PlayerCharacter->stats->isCrouching = false;
		PlayerCharacter->UnCrouch();
	}
	PlayerCharacter->ChangeMoveSpeed(PlayerCharacter->stats->isSprinting ? PlayerCharacter->stats->sprintSpeed : PlayerCharacter->stats->walkSpeed);
}

void AMainPlayerController::HandleBash() {
	if (!PlayerCharacter->stats->isGrounded) {
		PlayerCharacter->stats->isBashing = true;
	}
}

void AMainPlayerController::HandleCancel()
{
	bIsMenuOpen = !bIsMenuOpen;
}
