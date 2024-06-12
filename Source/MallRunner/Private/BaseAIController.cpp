// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAIController.h"
#include "BaseNPC.h"


void ABaseAIController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	ABaseNPC* npcPawn = Cast<ABaseNPC>(aPawn);

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
}

void ABaseAIController::OnUnPossess()
{
	Super::OnUnPossess();
}
