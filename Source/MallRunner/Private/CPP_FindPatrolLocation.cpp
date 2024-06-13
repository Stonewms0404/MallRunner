// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_FindPatrolLocation.h"
#include <BaseAIController.h>
#include <NavigationSystem.h>
#include <EnemyNPC.h>

UCPP_FindPatrolLocation::UCPP_FindPatrolLocation(FObjectInitializer const& ObjectInitializer) {
	NodeName = "Find Patrol Location";
}

EBTNodeResult::Type UCPP_FindPatrolLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const {

	if (auto* const controller = Cast<ABaseAIController>(OwnerComp.GetAIOwner())) {
		if (auto* const npc = Cast<AEnemyNPC>(controller->GetPawn())) {
			npc->GetSetPatrolLocation();
			OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName("PatrolLocation"), npc->patrolLocation);

			FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}
