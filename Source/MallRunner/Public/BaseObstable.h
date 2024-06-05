// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseObstable.generated.h"

UCLASS()
class MALLRUNNER_API ABaseObstable : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Obstacle|Flippable|Variables")
	bool isFlippable = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Obstacle|Flippable|Variables")
	bool hasFlipped = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Obstacle|Hideable|Variables")
	bool isHideable = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Obstacle|Breakable|Variables")
	bool isBashable = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Obstacle|Breakable|Variables")
	bool canBash = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Obstacle|Breakable|Variables")
	int weight = 1;

	UFUNCTION(BlueprintImplementableEvent, Category = "Breakable|Events")
	void ChangeColor(int selection);

	UFUNCTION(BlueprintCallable, Category = "Obstacles|Breakable|Functions")
	void CheckWeight(int playerWeight);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Sets default values for this actor's properties
	ABaseObstable();

};
