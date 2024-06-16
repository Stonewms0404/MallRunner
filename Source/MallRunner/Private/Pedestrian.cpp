// Fill out your copyright notice in the Description page of Project Settings.


#include "Pedestrian.h"



void APedestrian::BeginPlay() {
	controller = Cast<APedestrianController>(GetController());
}

void APedestrian::Tick(float deltaTime) {
	Super::Tick(deltaTime);
}
