// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/TrcgPlanetStatsManager.h"


// Sets default values
ATrcgPlanetStatsManager::ATrcgPlanetStatsManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

UTrcgPlanetStat* ATrcgPlanetStatsManager::GetStatFromClass(const TSubclassOf<UTrcgPlanetStat> Class)
{
	for (UTrcgPlanetStat* Stat : Stats)
	{
		if (Class == Stat->GetClass()) return Stat;
	}

	return nullptr;
}

