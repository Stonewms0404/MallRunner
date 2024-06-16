// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAIController.h"
#include "BaseNPC.h"
#include <EnhancedInputSubsystems.h>


ABaseAIController::ABaseAIController(FObjectInitializer const& ObjectInitializer) {

}

void ABaseAIController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
	if (ABaseNPC* const npcPawn = Cast<ABaseNPC>(aPawn)) {
		npc = npcPawn;

		switch (npcType) {
		case ENPCType::VE_Light:
			npc->InitializeStats(&LightEnemy);
			break;
		case ENPCType::VE_Normal:
			npc->InitializeStats(&NormalEnemy);
			break;
		case ENPCType::VE_Heavy:
			npc->InitializeStats(&HeavyEnemy);
			break;
		}
		
		if (UBehaviorTree* const tree = npc->GetBehaviorTree()) {
			UBlackboardComponent* b;
			UseBlackboard(tree->BlackboardAsset, b);
			Blackboard = b;
			RunBehaviorTree(tree);
		}
	}

}

void ABaseAIController::OnUnPossess()
{
	Super::OnUnPossess();
}
