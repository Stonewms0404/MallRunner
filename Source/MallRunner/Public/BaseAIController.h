#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include <EnhancedInputComponent.h>
#include "GameFramework/CharacterMovementComponent.h"
#include "BaseNPC.h"
#include "BaseAIController.generated.h"


UENUM(BlueprintType)
enum class ENPCType : uint8 {
	VE_Light = 0		UMETA(DisplayName = "Light"),
	VE_Normal = 1		UMETA(DisplayName = "Normal"),
	VE_Heavy = 2		UMETA(DisplayName = "Heavy")
};

UCLASS()
class MALLRUNNER_API ABaseAIController : public AAIController
{
	GENERATED_BODY()
public:
	explicit ABaseAIController(FObjectInitializer const& ObjectInitializer);


	UPROPERTY(EditDefaultsOnly, Category = "NPC|Enemy|Variables")
	bool canAlert = false;
	UPROPERTY(EditDefaultsOnly, Category = "NPC|Enemy|Variables")
	bool canCatch = false;
	UPROPERTY(EditDefaultsOnly, Category = "NPC|Variables")
	ENPCType npcType = ENPCType::VE_Light;

	ABaseNPC* npc;


protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Stats")
	FNPCStruct LightEnemy;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Stats")
	FNPCStruct NormalEnemy;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Stats")
	FNPCStruct HeavyEnemy;

	virtual void OnPossess(APawn* aPawn) override;
	virtual void OnUnPossess() override;

private:

};
