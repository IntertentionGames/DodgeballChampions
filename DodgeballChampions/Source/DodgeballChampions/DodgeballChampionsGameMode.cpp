// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "DodgeballChampionsGameMode.h"
#include "DodgeballChampionsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADodgeballChampionsGameMode::ADodgeballChampionsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
