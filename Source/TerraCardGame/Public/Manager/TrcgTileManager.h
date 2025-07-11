// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "General/TrcgActor.h"
#include "TrcgTileManager.generated.h"

class UTrcgLevelPlanetData;
struct FGameplayTag;
class ATrcgTile;

UCLASS(Blueprintable)
class TERRACARDGAME_API ATrcgTileManager : public ATrcgActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATrcgTileManager();

	UFUNCTION(BlueprintCallable, Category = "TRCG")
	void GenerateGrid();

	UFUNCTION(BlueprintCallable, Category = "TRCG")
	ATrcgTile* GetTileAtIndex(const int32 Index) const;

	UFUNCTION(BlueprintCallable, Category = "TRCG")
	TArray<ATrcgTile*> GetNeighbourTiles(const int32 Index);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ExposeOnSpawn))
	int GridXSize = 10;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ExposeOnSpawn))
	int GridYSize = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ATrcgTile*> Tiles;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<ATrcgTile> TileClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TRCG", meta = (ExposeOnSpawn))
	UTrcgLevelPlanetData* LevelPlanetData;

	UFUNCTION(BlueprintPure, Category = "TRCG")
	bool HasNeighbourTilesWithTileTag(const int32 Index, const FGameplayTag Tag);

	UFUNCTION(BlueprintPure, Category = "TRCG")
	bool AllHaveTileTag(const FGameplayTag Tag);
};
