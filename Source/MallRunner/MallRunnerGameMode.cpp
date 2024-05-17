// Copyright Epic Games, Inc. All Rights Reserved.

#include "MallRunnerGameMode.h"
#include "MallRunnerCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMallRunnerGameMode::AMallRunnerGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
