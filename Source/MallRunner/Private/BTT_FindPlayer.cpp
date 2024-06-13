// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_FindPlayer.h"
#include "EnemyNPC.h"
#include <BaseAIController.h>

UBTT_FindPlayer::UBTT_FindPlayer(FObjectInitializer const& ObjectInitializer) {
	NodeName = "Find Player";
}

EBTNodeResult::Type UBTT_FindPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const {

	if (auto* const controller = Cast<ABaseAIController>(OwnerComp.GetAIOwner())) {
		if (auto* const npc = Cast<AEnemyNPC>(controller->GetPawn())) {
			OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName("LastPlayerLocation"), npc->lastPlayerLocation);
		}
	}

	return EBTNodeResult::Failed;
}
