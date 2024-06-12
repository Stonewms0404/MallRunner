// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseNPC.h"

// Sets default values
ABaseNPC::ABaseNPC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ABaseNPC::InitializeStats(FNPCStruct baseStats) {
	stats = baseStats;

	charMoveComp->MaxWalkSpeed = stats.walkSpeed;
	charMoveComp->BrakingFriction = stats.handling;
	charMoveComp->GroundFriction = stats.traction;
	charMoveComp->MaxAcceleration = stats.accelerationSpeed;
	charMoveComp->GravityScale = stats.gravity;
	capsule->SetCapsuleHalfHeight(stats.normalHeight);
}

// Called when the game starts or when spawned
void ABaseNPC::BeginPlay()
{
	Super::BeginPlay();
	
	charMoveComp = GetCharacterMovement();
	capsule = GetCapsuleComponent();
}

void ABaseNPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABaseNPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
void ABaseNPC::StartIdleTimer() {
	idleTimer = 0;
	idleTimerLength = rand() % 3;
}

bool ABaseNPC::UseIdleTimer(float deltaTime) {
	idleTimer += deltaTime;

	return idleTimer >= idleTimerLength;
}

void ABaseNPC::CheckPatrolLocation() {
	atPatrolLocation = (GetActorLocation() - patrolLocation).Length() < 5;
}