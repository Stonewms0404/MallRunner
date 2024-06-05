// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseObstable.h"

// Sets default values
ABaseObstable::ABaseObstable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ABaseObstable::CheckWeight(int playerWeight){
	if (playerWeight >= weight + 3) {
		canBash = true;
		ChangeColor(1);
	}
	else if (playerWeight >= weight) {
		canBash = (rand() % 100 + 1) > 50;
		ChangeColor(2);
	}
	else {
		canBash = false;
		ChangeColor(3);
	}
}

// Called when the game starts or when spawned
void ABaseObstable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseObstable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

