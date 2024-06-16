// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_Rotate.h"
#include <EnemyNPC.h>

UBTT_Rotate::UBTT_Rotate(FObjectInitializer const& ObjectInitializer) {
	NodeName = "Rotate Character";
}

EBTNodeResult::Type UBTT_Rotate::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if (auto* const controller = Cast<ABaseAIController>(OwnerComp.GetAIOwner())) {
		if (auto* const npc = Cast<ABaseNPC>(controller->GetPawn())) {
			FRotator rot = npc->GetActorRotation();
			npc->SetActorRotation(rot + addedRot);

			return EBTNodeResult::Succeeded;
		}
	}
	return EBTNodeResult::Failed;
}
