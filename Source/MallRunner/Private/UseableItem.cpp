// Fill out your copyright notice in the Description page of Project Settings.


#include "UseableItem.h"

void AUseableItem::CheckCrackedStatus() {
	isCracked = (sin(rand()) + 1) / 2 >= 0.5;
}
