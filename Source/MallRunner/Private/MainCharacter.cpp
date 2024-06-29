#include "MainCharacter.h"
#include "MainPlayerController.h"
#include "Components/CapsuleComponent.h"

AMainCharacter::AMainCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	statsptr = new FPlayerStats;
	stats = *statsptr;
	charMoveComp = GetCharacterMovement();
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMainCharacter::InitializeStats(FPlayerStats* newStats) {
	statsptr = newStats;
	stats = *statsptr;

	charMoveComp->MaxWalkSpeed = statsptr->sprintSpeed;
	charMoveComp->BrakingFriction = statsptr->handling;
	charMoveComp->GroundFriction = statsptr->traction;
	charMoveComp->GravityScale = statsptr->gravity;
	charMoveComp->JumpZVelocity = statsptr->jumpHeight;
	charMoveComp->MaxAcceleration = statsptr->accelerationSpeed;
	GetCapsuleComponent()->SetCapsuleHalfHeight(statsptr->normalHeight);
}

void AMainCharacter::ChangeWeight(int addedWeight) {
	statsptr->weight += addedWeight;
}

void AMainCharacter::OnEndBash() {
	charMoveComp->MaxWalkSpeed = statsptr->sprintSpeed;
}

void AMainCharacter::AddItem(AUseableItem* item) {
	if (statsptr->item1 == nullptr)
		statsptr->item1 = item;
	else if (statsptr->item2 == nullptr)
		statsptr->item2 = item;
	else if (statsptr->item1->selected) {
		delete statsptr->item2;
		statsptr->item2 = item;
	}
	else if (statsptr->item2->selected) {
		delete statsptr->item1;
		statsptr->item1 = item;
	}
	stats = *statsptr;
}

void AMainCharacter::AddCollectible(ACollectibleItem* item) {
	statsptr->collectibles.Add(item);
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

