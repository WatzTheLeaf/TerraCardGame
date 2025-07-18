﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "General/TrcgObject.h"
#include "TrcgCardEffect.generated.h"

class UTrcgPlanetStat;
struct FGameplayTag;
class UTrcgBiomeInteractionData;
class ATrcgTile;
/**
 * 
 */
UCLASS(Blueprintable)
class TERRACARDGAME_API UTrcgCardEffect : public UTrcgObject
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "TRCG")
	void StartEffect(int OnTile);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "TRCG")
	TMap<TSubclassOf<UTrcgPlanetStat>, int> PreviewEffect(int OnTile);

	UFUNCTION(BlueprintCallable, Category = "TRCG")
	TMap<TSubclassOf<UTrcgPlanetStat>, int> StatChangesFromData(UTrcgBiomeInteractionData* Data);

	UFUNCTION(BlueprintCallable, Category = "TRCG")
	void ApplyBiomeInteraction(UTrcgBiomeInteractionData* Data, int OnTile);

	UFUNCTION(BlueprintCallable, Category = "TRCG")
	void ApplyBiomeInteractionWithRef(UTrcgBiomeInteractionData* Data, ATrcgTile* Tile);
};
