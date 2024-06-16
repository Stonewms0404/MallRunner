// Fill out your copyright notice in the Description page of Project Settings.


#include "BTS_CheckPlayer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include <EnemyNPC.h>


UBTS_CheckPlayer::UBTS_CheckPlayer() {
	NodeName = "Check Player";
}

void UBTS_CheckPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) {
	if (auto* const controller = Cast<ABaseAIController>(OwnerComp.GetAIOwner())) {
		if (auto* const npc = Cast<AEnemyNPC>(controller->GetPawn())) {
			OwnerComp.GetBlackboardComponent()->SetValueAsBool(FName("CanSeePlayer"), npc->canSeePlayer);
			OwnerComp.GetBlackboardComponent()->SetValueAsBool(FName("PlayerLost"), npc->playerLost);
			OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName("LastPlayerLocation"), npc->lastPlayerLocation);
		}
	}
}
