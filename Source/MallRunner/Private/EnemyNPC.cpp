// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyNPC.h"

void AEnemyNPC::BeginPlay() {
	Super::BeginPlay();

	controller = Cast<AEnemyController>(GetController());
}

void AEnemyNPC::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
}