// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "MainPlayerController.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	charMoveComp = GetCharacterMovement();
	stats = new PlayerStats();

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	stats->isGrounded = charMoveComp->IsMovingOnGround();

	if (stats->isSprinting) {
		if (VectorToFloat(charMoveComp->Velocity) < stats->walkSpeed / 1.25f) {
			stats->isSprinting = false;
			ChangeMoveSpeed(stats->walkSpeed);
		}
	}

	if (stats->isSliding && stats->isJumping) {
		stats->isJumping = !stats->isGrounded;
		if (charMoveComp->MaxWalkSpeed < stats->sprintSpeed)
			charMoveComp->MaxWalkSpeed = stats->sprintSpeed;
		else
			charMoveComp->MaxWalkSpeed = charMoveComp->MaxWalkSpeed - 10;

	}

	if (charMoveComp->IsCrouching()) {
		stats->isSliding = VectorToFloat(charMoveComp->Velocity) > stats->walkSpeed / 2;
		if (stats->isSliding)
			Slide();
		else
			charMoveComp->MaxWalkSpeedCrouched = stats->crouchSpeed;
	}

	if (stats->isBashing) {
		Bash();
		stats->isBashing = stats->isGrounded;
	}
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void AMainCharacter::ChangeMoveSpeed(float speed) {
	charMoveComp->MaxWalkSpeed = speed;
}

void AMainCharacter::ChangeCrouchSpeed(float speed) {
	charMoveComp->MaxWalkSpeedCrouched = speed;
}

void AMainCharacter::SetBaseVariables(PlayerStats* newStats) {
	stats = newStats;
}

void AMainCharacter::Slide() {
	charMoveComp->MaxWalkSpeedCrouched =
		charMoveComp->MaxWalkSpeedCrouched < stats->crouchSpeed ? stats->crouchSpeed : VectorToFloat(charMoveComp->Velocity) - stats->slideFriction;
}

void AMainCharacter::Bash() {
	FVector* vec = new FVector(0, 0, charMoveComp->Velocity.Z - stats->GetBashingSpeed());
	charMoveComp->Velocity = *vec;
}