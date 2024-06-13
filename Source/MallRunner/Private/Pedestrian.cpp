// Fill out your copyright notice in the Description page of Project Settings.


#include "Pedestrian.h"



void APedestrian::BeginPlay() {
	controller = Cast<APedestrianController>(GetController());
}

void APedestrian::Tick(float deltaTime) {
	Super::Tick(deltaTime);
}


float APedestrian::GetRandomSpeed()
{
	speed = stats.walkSpeed + (rand() % (int)((stats.sprintSpeed / stats.walkSpeed) * 1000.0f)) / 1000.0f;
	return speed;
}
