// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTS_CheckPlayer.generated.h"

/**
 * 
 */
UCLASS()
class MALLRUNNER_API UBTS_CheckPlayer : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
public:
	explicit UBTS_CheckPlayer();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
