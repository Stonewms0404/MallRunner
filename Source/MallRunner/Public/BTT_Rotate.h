// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BTT_Rotate.generated.h"

/**
 * 
 */
UCLASS()
class MALLRUNNER_API UBTT_Rotate : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

	explicit UBTT_Rotate(FObjectInitializer const& ObjectInitializer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const;
	const FRotator addedRot = FRotator(0, 0 , 5.0F);
};
