// Fill out your copyright notice in the Description page of Project Settings.


#include "Cards/TrcgCardEffect.h"

#include "General/TrcgGameInstance.h"
#include "Manager/TrcgPlanetStatsManager.h"
#include "Manager/TrcgTileManager.h"
#include "World/TrcgBiomeInteractionData.h"
#include "World/TrcgTile.h"

void UTrcgCardEffect::ApplyBiomeInteraction(UTrcgBiomeInteractionData* Data, const int OnTile)
{
	for (TTuple<TSubclassOf<UTrcgPlanetStat>, int32> const Stat : Data->StatChanges)
	{
		GetTrcgGameInstance()->StatManager->GetStatFromClass(Stat.Key)->ApplyStatChange(Stat.Value);
	}
	GetTrcgGameInstance()->TileManager->GetTileAtIndex(OnTile)->TileTags = Data->TagsToSet;
}

void UTrcgCardEffect::ApplyBiomeInteractionWithRef(UTrcgBiomeInteractionData* Data, ATrcgTile* Tile)
{
	for (TTuple<TSubclassOf<UTrcgPlanetStat>, int32> const Stat : Data->StatChanges)
	{
		GetTrcgGameInstance()->StatManager->GetStatFromClass(Stat.Key)->ApplyStatChange(Stat.Value);
	}
	Tile->TileTags = Data->TagsToSet;
}
