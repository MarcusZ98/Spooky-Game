// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpookyGameGameMode.h"
#include "SpookyGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASpookyGameGameMode::ASpookyGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
