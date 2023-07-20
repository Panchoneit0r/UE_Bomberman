// Copyright Epic Games, Inc. All Rights Reserved.

#include "TrueMenuMPlayerGameMode.h"
#include "TrueMenuMPlayerCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATrueMenuMPlayerGameMode::ATrueMenuMPlayerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
