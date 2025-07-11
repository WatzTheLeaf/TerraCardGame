// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TrcgGameInstance.generated.h"

class UTrcgLevelPlanetData;
class UTrcgCardData;
class ATrcgPlanetStatsManager;
class ATrcgTileManager;

/**
 * 
 */
UCLASS(Blueprintable)
class TERRACARDGAME_API UTrcgGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(Category = "TRCG", BlueprintReadWrite)
	ATrcgTileManager* TileManager;

	UPROPERTY(Category = "TRCG", BlueprintReadWrite)
	ATrcgPlanetStatsManager* StatManager;

	UPROPERTY(Category = "TRCG", BlueprintReadOnly, EditDefaultsOnly)
	TArray<UTrcgCardData*> CardData;

	UPROPERTY(Category = "TRCG", BlueprintReadWrite)
	TMap<UTrcgCardData*, int> GlobalDeck;

	UPROPERTY(Category = "TRCG", BlueprintReadWrite, EditDefaultsOnly)
	int GlobalDeckMaxSize;

	UPROPERTY(EditAnywhere, Category = "TRCG", BlueprintReadWrite)
	UTrcgLevelPlanetData* CurrentLevelData;

	UFUNCTION(BlueprintCallable)
	int GetGlobalDeckSize();

	UFUNCTION(BlueprintPure)
	bool IsDeckFull();
	
};
