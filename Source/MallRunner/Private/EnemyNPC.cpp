// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyNPC.h"

void AEnemyNPC::BeginPlay() {
	Super::BeginPlay();

	controller = Cast<AEnemyController>(GetController());
}

void AEnemyNPC::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
	charMoveComp->MaxWalkSpeed = isRunning ? (inCrowd ? stats.sprintSpeed / 1.5 : stats.sprintSpeed) : (inCrowd ? stats.walkSpeed / 1.5 : stats.walkSpeed);

	switch (state) {
	case EEnemyState::VE_Idle:
		if (!idleTimerStarted) {
			StartIdleTimer();
			break;
		}

		if (UseIdleTimer(deltaTime))
			state = EEnemyState::VE_Patrolling;
		break;

	case EEnemyState::VE_Patrolling:
		if (atPatrolLocation) {
			GetPatrolLocation();

			state = EEnemyState::VE_Idle;
			break;
		}

		controller->MoveToLocation(patrolLocation);
		
		CheckPatrolLocation();
		break;

	case EEnemyState::VE_Searching:
		if (!searchTimerStarted) {
			StartSearchTimer();
			break;
		}

		if (UseSearchTimer(deltaTime)) {
			state = EEnemyState::VE_Idle;
			break;
		}

		controller->MoveToLocation(lastPlayerLocation);
		break;

	case EEnemyState::VE_Chasing:
		if (isFrozen) {

			break;
		}

		if (!canSeePlayer) {
			state = EEnemyState::VE_Searching;
			break;
		}

		controller->MoveToActor(playerController->PlayerCharacter, -1, false);
		break;
	}
}

void AEnemyNPC::StartSearchTimer() {
	searchTimer = 0;
	searchTimerLength = rand() % 10;
}

bool AEnemyNPC::UseSearchTimer(float deltaTime) {
	searchTimer += deltaTime;

	return idleTimer >= searchTimerLength;
}

void AEnemyNPC::GetPatrolLocation() {
	FVector playerPos = playerController->PlayerCharacter->GetActorLocation();
	patrolLocation = playerPos + FVector((rand() % 200) - 100, (rand() % 200) - 100, playerPos.Z);
}