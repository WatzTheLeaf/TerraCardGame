// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "TrcgBiomeInteractionData.generated.h"

class UTrcgPlanetStat;
/**
 * 
 */
UCLASS(BlueprintType)
class TERRACARDGAME_API UTrcgBiomeInteractionData : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTagContainer TagsToSet;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<TSubclassOf<UTrcgPlanetStat>, int32> StatChanges;
};
