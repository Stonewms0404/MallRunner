// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseNPC.h"

// Sets default values
ABaseNPC::ABaseNPC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	capsule = GetCapsuleComponent();
	charMoveComp = GetCharacterMovement();
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

UBehaviorTree* ABaseNPC::GetBehaviorTree() const
{
	return Tree;
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