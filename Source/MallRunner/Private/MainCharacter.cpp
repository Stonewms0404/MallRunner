#include "MainCharacter.h"
#include "MainPlayerController.h"
#include "Components/CapsuleComponent.h"

AMainCharacter::AMainCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	stats = new PlayerStats;
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

void AMainCharacter::InitializeStats(AMainCharacter::PlayerStats* newStats) {
	stats = newStats;
	charMoveComp->MaxWalkSpeed = stats->sprintSpeed;
	charMoveComp->BrakingFriction = stats->handling;
	charMoveComp->GroundFriction = stats->traction;
	charMoveComp->GravityScale = stats->gravity;
	charMoveComp->JumpZVelocity = stats->jumpHeight;
	charMoveComp->MaxAcceleration = stats->accelerationSpeed;
	GetCapsuleComponent()->SetCapsuleHalfHeight(stats->normalHeight);
}

void AMainCharacter::OnEndBash() {
	charMoveComp->MaxWalkSpeed = stats->sprintSpeed;
}

//void AMainCharacter::AddItem(ABaseItem* item) {
//	if (stats->item1 == nullptr)
//		stats->item1 = item;
//	else if (stats->item2 == nullptr)
//		stats->item2 = item;
//	else if (stats->item1->selected) {
//		delete stats->item2;
//		stats->item2 = item;
//	}
//	else if (stats->item2->selected) {
//		delete stats->item1;
//		stats->item1 = item;
//	}
//}

void AMainCharacter::GotCaught() {

}

void AMainCharacter::AddCollectible() {

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

