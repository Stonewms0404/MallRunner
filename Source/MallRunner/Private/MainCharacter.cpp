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

	if (stats->isCrouching) {
		charMoveComp->MaxWalkSpeed = Lerp(charMoveComp->MaxWalkSpeed, stats->crouchSpeed, DeltaTime);
	}

	if (stats->isSprinting && !stats->isBashing) {
		if (VectorToFloat(charMoveComp->Velocity) < stats->walkSpeed / 1.25f) {
			stats->isSprinting = false;
			ChangeMoveSpeed(stats->walkSpeed);
		}
	}

	if (stats->isSliding && stats->isJumping) {
		stats->isJumping = !stats->isGrounded;
		if (charMoveComp->MaxWalkSpeed < stats->sprintSpeed) {
			charMoveComp->MaxWalkSpeed = stats->sprintSpeed;
			stats->isSprinting = true;
			stats->isCrouching = false;
			OnCancelSlide(stats->sprintSpeed);
		}

	}

	if (stats->isSlaming && !stats->isGrounded) {
		Slam();
		stats->isSlaming = stats->isGrounded;
	}

	if (stats->isBashing && stats->isGrounded) {
		if (VectorToFloat(charMoveComp->Velocity) < 50) {
			stats->isBashing = false;
			charMoveComp->MaxWalkSpeed = stats->walkSpeed;
		}
		else
			charMoveComp->MaxWalkSpeed = SlowToSpeed(charMoveComp->MaxWalkSpeed, 5);
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

void AMainCharacter::SetCrouching(bool value) {
	stats->isCrouching = value;
	OnCrouchChanged(!stats->isCrouching);
}

void AMainCharacter::Slam() {
	FVector* vec = new FVector(0, 0, charMoveComp->Velocity.Z - stats->GetSlamingSpeed());
	charMoveComp->Velocity = *vec;
}

void AMainCharacter::Bash() {
	charMoveComp->Velocity = GetActorForwardVector() * stats->GetBashingSpeed();
}
