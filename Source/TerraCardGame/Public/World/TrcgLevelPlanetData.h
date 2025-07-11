// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TrcgLevelPlanetData.generated.h"

struct FGameplayTag;
class UTrcgPlanetStat;
/**
 * 
 */
UCLASS(BlueprintType)
class TERRACARDGAME_API UTrcgLevelPlanetData : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TMap<TSubclassOf<UTrcgPlanetStat>, FIntPoint> StatConditions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FIntPoint Range;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName LevelPlanetName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (ClampMin = 1, ClampMax = 100))
	TMap<FGameplayTag, int> BaseTiles;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool CheckForCompletion = true;
};
