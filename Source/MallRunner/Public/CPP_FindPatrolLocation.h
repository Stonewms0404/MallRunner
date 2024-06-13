// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "CPP_FindPatrolLocation.generated.h"

/**
 * 
 */
UCLASS()
class MALLRUNNER_API UCPP_FindPatrolLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	explicit UCPP_FindPatrolLocation(FObjectInitializer const& ObjectInitializer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const;
	float SearchRadius = 5000.0f;
};
