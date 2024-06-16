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
			auto const Origin = npc->GetActorLocation();

			if (auto* const NavSys = UNavigationSystemV1::GetCurrent(GetWorld())) {
				FNavLocation loc;
				if (NavSys->GetRandomReachablePointInRadius(Origin, SearchRadius, loc)) {
					OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName("PatrolLocation"), loc.Location);

					FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
					return EBTNodeResult::Succeeded;
				}
			}

		}
	}

	return EBTNodeResult::Failed;
}
