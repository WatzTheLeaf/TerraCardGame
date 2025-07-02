// Fill out your copyright notice in the Description page of Project Settings.


#include "TerraCardGame/Public/General/TrcgObject.h"

#include "Kismet/GameplayStatics.h"
#include "TerraCardGame/Public/General/TrcgGameInstance.h"

UTrcgGameInstance* UTrcgObject::GetTrcgGameInstance() const
{
	UTrcgGameInstance* GI = Cast<UTrcgGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	check(GI);
	return GI;
}

TMap<TSubclassOf<UTrcgPlanetStat>, int> UTrcgObject::CombineMaps(
	const TMap<TSubclassOf<UTrcgPlanetStat>, int>& Map1,
	const TMap<TSubclassOf<UTrcgPlanetStat>, int>& Map2)
{
	TMap<TSubclassOf<UTrcgPlanetStat>, int> CombinedMap;
	for (const TPair<TSubclassOf<UTrcgPlanetStat>, int>& Pair : Map1)
	{
		CombinedMap.Add(Pair.Key, Pair.Value);
	}
	for (const TPair<TSubclassOf<UTrcgPlanetStat>, int>& Pair : Map2)
	{
		if (CombinedMap.Contains(Pair.Key))
		{
			CombinedMap[Pair.Key] += Pair.Value;
		}
		else
		{
			CombinedMap.Add(Pair.Key, Pair.Value);
		}
	}
	return CombinedMap;
}
