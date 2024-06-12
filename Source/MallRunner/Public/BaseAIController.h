#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseAIController.generated.h"

USTRUCT(BlueprintType)
struct FNPCStruct {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Stats|Variables", meta = (ToolTip = "MaxWalkSpeed of the Character Movement Component for sprinting"))
	float sprintSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Stats|Variables", meta = (ToolTip = "MaxWalkSpeed of the Character Movement Component for walking"))
	float walkSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Stats|Variables", meta = (ToolTip = "MaxAcceleration of the Character Movement Component\n  The player will change it's velocity every second by this value"))
	float accelerationSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Stats|Variables", meta = (ToolTip = "GroundFriction of the Character Movement Component\n  The player will use this friction on the ground to move\n    Max of 8"))
	float traction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Stats|Variables", meta = (ToolTip = "BrakingFriction of the Character Movement Component\n  The player will use this friction on the ground to move\n    Max of 1"))
	float handling;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Stats|Variables", meta = (ToolTip = "Normal walk height of the player"))
	float normalHeight;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Stats|Variables", meta = (ToolTip = "Normal walk height of the player"))
	float forgetTimer;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Stats|Variables", meta = (ToolTip = "The scale of gravity that the player will fall"))
	float gravity;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "NPC|Stats|Variables", meta = (ToolTip = "The player's weight and how easily it is for a the player to break \"Breakable\" Objects"))
	int weight;

	UPROPERTY(BlueprintReadOnly, Category = "NPC|Variables")
	bool canAlert;
	UPROPERTY(BlueprintReadOnly, Category = "NPC|Variables")
	bool canCatch;
};

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
	UPROPERTY(EditDefaultsOnly, Category = "NPC|Enemy|Variables")
	bool canAlert;
	UPROPERTY(EditDefaultsOnly, Category = "NPC|Enemy|Variables")
	bool canCatch;
	UPROPERTY(EditDefaultsOnly, Category = "NPC|Variables")
	ENPCType npcType;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "NPC|Stats")
	FNPCStruct LightEnemy;
	UPROPERTY(EditDefaultsOnly, Category = "NPC|Stats")
	FNPCStruct NormalEnemy;
	UPROPERTY(EditDefaultsOnly, Category = "NPC|Stats")
	FNPCStruct HeavyEnemy;

	virtual void OnPossess(APawn* aPawn) override;
	virtual void OnUnPossess() override;
};
