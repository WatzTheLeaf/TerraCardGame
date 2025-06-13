// Fill out your copyright notice in the Description page of Project Settings.


#include "TerraCardGame/Public/General/TrcgGameInstance.h"

int UTrcgGameInstance::GetGlobalDeckSize()
{
	int Counter = 0;
	
	for (const TTuple<UTrcgCardData*, int> CardEntry : GlobalDeck)
	{
		Counter += CardEntry.Value;
	}
	
	return Counter;
}

bool UTrcgGameInstance::IsDeckFull()
{
	return GetGlobalDeckSize() >= GlobalDeckMaxSize;
}
