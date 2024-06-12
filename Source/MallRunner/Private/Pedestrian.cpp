// Fill out your copyright notice in the Description page of Project Settings.


#include "Pedestrian.h"



void APedestrian::BeginPlay() {
	controller = Cast<APedestrianController>(GetController());

	state = EPedestrianState::VE_Idle;
	idleTimerStarted = false;
}

void APedestrian::Tick(float deltaTime) {
	Super::Tick(deltaTime);

	switch (state) {
	case EPedestrianState::VE_Idle:
		if (!idleTimerStarted) {
			StartIdleTimer();
			break;
		}

		if (UseIdleTimer(deltaTime)) {
			state = EPedestrianState::VE_Patrolling;
			idleTimerStarted = false;

			charMoveComp->MaxWalkSpeed = GetRandomSpeed();
		}
		break;

	case EPedestrianState::VE_Patrolling:
		if (atPatrolLocation) {
			atPatrolLocation = false;
			GetPatrolLocation();

			state = EPedestrianState::VE_Idle;
			break;
		}

		controller->MoveToLocation(patrolLocation);

		CheckPatrolLocation();
		break;
	}
}

void APedestrian::GetPatrolLocation() {
	GetRandomNPCLocation();
	patrolLocation = randomNPCLocation + FVector((rand() % 200) - 100, (rand() % 200) - 100, randomNPCLocation.Z);
}

float APedestrian::GetRandomSpeed()
{
	speed = stats.walkSpeed + (rand() % (int)((stats.sprintSpeed / stats.walkSpeed) * 1000.0f)) / 1000.0f;
	return speed;
}
