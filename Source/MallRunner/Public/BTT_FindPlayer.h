// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BTT_FindPlayer.generated.h"

/**
 * 
 */
UCLASS()
class MALLRUNNER_API UBTT_FindPlayer : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	explicit UBTT_FindPlayer(FObjectInitializer const& ObjectInitializer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const;
};
