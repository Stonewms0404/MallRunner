// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Decorators/BTDecorator_BlackboardBase.h"
#include "BTD_CanSeePlayer.generated.h"

/**
 * 
 */
UCLASS()
class MALLRUNNER_API UBTD_CanSeePlayer : public UBTDecorator_BlackboardBase
{
	GENERATED_BODY()

public:
	explicit UBTD_CanSeePlayer(FObjectInitializer const& ObjectInitializer);
	
};
