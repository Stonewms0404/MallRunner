// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseObstable.h"

// Sets default values
ABaseObstable::ABaseObstable()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ABaseObstable::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseObstable::CheckWeight(int playerWeight, int weight){
	if (playerWeight >= weight + 3) {
		canBash = true;
		ChangeColor(1);
	}
	else if (playerWeight >= weight) {
		canBash = (rand() % 100) / 100.0 >= 0.5;
		ChangeColor(2);
	}
	else {
		canBash = false;
		ChangeColor(3);
	}
}

