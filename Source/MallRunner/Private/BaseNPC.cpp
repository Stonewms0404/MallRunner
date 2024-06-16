// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseNPC.h"

// Sets default values
ABaseNPC::ABaseNPC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	statsptr = new FNPCStruct();
	stats = *statsptr;

	charMoveComp = GetCharacterMovement();
}

void ABaseNPC::InitializeStats(FNPCStruct* baseStats) {
	statsptr = baseStats;
	stats = *statsptr;

	charMoveComp->MaxWalkSpeed = statsptr->walkSpeed;
	charMoveComp->BrakingFriction = statsptr->handling;
	charMoveComp->GroundFriction = statsptr->traction;
	charMoveComp->MaxAcceleration = statsptr->accelerationSpeed;
	charMoveComp->GravityScale = statsptr->gravity;
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