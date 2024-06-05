// Fill out your copyright notice in the Description page of Project Settings.


#include <MainPlayerController.h>
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
		EnhancedInputComponent->BindAction(ActionJump, ETriggerEvent::Started,
			this, &AMainPlayerController::StartJump);
		EnhancedInputComponent->BindAction(ActionJump, ETriggerEvent::Completed,
			this, &AMainPlayerController::EndJump);
	}

	if (ActionCrouch) {
		EnhancedInputComponent->BindAction(ActionCrouch, ETriggerEvent::Started,
			this, &AMainPlayerController::StartCrouch);
		EnhancedInputComponent->BindAction(ActionCrouch, ETriggerEvent::Completed,
			this, &AMainPlayerController::EndCrouch);
	}

	if (ActionWalk) {
		EnhancedInputComponent->BindAction(ActionWalk, ETriggerEvent::Started,
			this, &AMainPlayerController::StartWalk);
		EnhancedInputComponent->BindAction(ActionWalk, ETriggerEvent::Completed,
			this, &AMainPlayerController::EndWalk);
	}

	if (ActionBash) {
		EnhancedInputComponent->BindAction(ActionBash, ETriggerEvent::Started,
			this, &AMainPlayerController::HandleBash);
	}

	if (ActionFreeLook) {
		EnhancedInputComponent->BindAction(ActionFreeLook, ETriggerEvent::Triggered,
			this, &AMainPlayerController::StartFreeLook);
		EnhancedInputComponent->BindAction(ActionFreeLook, ETriggerEvent::Completed,
			this, &AMainPlayerController::EndFreeLook);
	}

	if (ActionCancel) {
		EnhancedInputComponent->BindAction(ActionCancel, ETriggerEvent::Triggered,
			this, &AMainPlayerController::HandleCancel);
	}

	AMainCharacter::PlayerStats* baseStats = new AMainCharacter::PlayerStats;
	baseStats->sprintSpeed = baseSprintSpeed;
	baseStats->walkSpeed = baseWalkSpeed;
	baseStats->crouchSpeed = baseCrouchSpeed;
	baseStats->slideSpeed = baseSlideSpeed;
	baseStats->traction = baseTraction;
	baseStats->handling = baseHandling;
	baseStats->accelerationSpeed = baseAccelerationSpeed;
	baseStats->normalHeight = baseNormalHeight;
	baseStats->crouchHeight = baseCrouchHeight;
	baseStats->weight = baseWeight;
	baseStats->gravity = baseGravity;
	baseStats->jumpHeight = baseJumpVelocity;

	PlayerCharacter->InitializeStats(baseStats);
}

void AMainPlayerController::OnUnPossess()
{
	EnhancedInputComponent->ClearActionBindings();

	Super::OnUnPossess();
}

void AMainPlayerController::HandleMove(const FInputActionValue & InputActionValue)
{
	const FVector2D MovementVector = InputActionValue.Get<FVector2D>();
	forward = PlayerCharacter->GetActorForwardVector();

	if (freeLooking) {
		PlayerCharacter->AddMovementInput(-forward, MovementVector.Y);
		PlayerCharacter->AddMovementInput(-PlayerCharacter->GetActorRightVector(), MovementVector.X);
	}
	else {
		PlayerCharacter->AddMovementInput(forward, MovementVector.Y);
		PlayerCharacter->AddMovementInput(PlayerCharacter->GetActorRightVector(), MovementVector.X);
	}

}

void AMainPlayerController::HandleLook(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

	AddYawInput(LookAxisVector.X);
	AddPitchInput(LookAxisVector.Y);
}

void AMainPlayerController::StartJump() {
	PlayerCharacter->EndSlide();
	PlayerCharacter->Jump();
}
void AMainPlayerController::EndJump() {
	PlayerCharacter->StopJumping();
}

void AMainPlayerController::StartCrouch() {
	FVector vel = PlayerCharacter->GetVelocity();
	float speed = AMainCharacter::VectorToFloat(vel);

	if (speed < PlayerCharacter->stats->sprintSpeed * 0.85)
		PlayerCharacter->OnCrouch(true,
			PlayerCharacter->stats->normalHeight,
			PlayerCharacter->stats->crouchHeight,
			PlayerCharacter->stats->sprintSpeed,
			PlayerCharacter->stats->crouchSpeed);
	else
		PlayerCharacter->OnSlide(
			PlayerCharacter->stats->normalHeight,
			PlayerCharacter->stats->crouchHeight,
			PlayerCharacter->stats->slideSpeed,
			PlayerCharacter->stats->crouchSpeed);

}
void AMainPlayerController::EndCrouch() {
	PlayerCharacter->EndSlide();
	PlayerCharacter->OnCrouch(false,
		PlayerCharacter->stats->normalHeight,
		PlayerCharacter->stats->crouchHeight,
		PlayerCharacter->stats->sprintSpeed,
		PlayerCharacter->stats->crouchSpeed);
}

void AMainPlayerController::StartWalk() {
	PlayerCharacter->OnAccelerate(PlayerCharacter->stats->walkSpeed);
	PlayerCharacter->EndSlide();
}
void AMainPlayerController::EndWalk() {
	PlayerCharacter->OnAccelerate(PlayerCharacter->stats->sprintSpeed);
}

void AMainPlayerController::HandleBash() {
	if (!hasBashed)
		PlayerCharacter->OnStartBash(PlayerCharacter->stats->sprintSpeed + 300, forward);
}

void AMainPlayerController::StartFreeLook() {
	if (!freeLooking)
		AddYawInput(360);
	freeLooking = true;
}
void AMainPlayerController::EndFreeLook() {
	AddYawInput(-360);
	freeLooking = false;
}

void AMainPlayerController::HandleCancel() {
	Pause();
}
