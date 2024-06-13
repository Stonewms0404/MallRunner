// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAIController.h"
#include "BaseNPC.h"


ABaseAIController::ABaseAIController(FObjectInitializer const& ObjectInitializer) {

}

void ABaseAIController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
	if (ABaseNPC* const npcPawn = Cast<ABaseNPC>(aPawn)) {
		switch (npcType) {
		case ENPCType::VE_Light:
			npcPawn->InitializeStats(LightEnemy);
			break;
		case ENPCType::VE_Normal:
			npcPawn->InitializeStats(NormalEnemy);
			break;
		case ENPCType::VE_Heavy:
			npcPawn->InitializeStats(HeavyEnemy);
			break;
		}
		
		if (UBehaviorTree* const tree = npcPawn->GetBehaviorTree()) {
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
