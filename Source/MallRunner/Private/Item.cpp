#include "Item.h"
UItem::UItem() {
	PrimaryComponentTick.bCanEverTick = false;
}

void UItem::BeginPlay() {
	Super::BeginPlay();
}