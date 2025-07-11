// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/TrcgTileManager.h"

#include "General/TrcgGameInstance.h"
#include "World/TrcgLevelPlanetData.h"
#include "World/TrcgTile.h"


// Sets default values
ATrcgTileManager::ATrcgTileManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATrcgTileManager::GenerateGrid()
{
	UTrcgLevelPlanetData* LevelPlanetData = GetTrcgGameInstance()->CurrentLevelData;
		
	if (!IsValid(TileClass) || !LevelPlanetData) return;

	if (LevelPlanetData->BaseTiles.Num() == 0) return;
	
	TArray<FGameplayTag> WeightedTags;
	for (const TPair<FGameplayTag, int32>& Pair : LevelPlanetData->BaseTiles)
	{
		for (int32 i = 0; i < Pair.Value; ++i)
		{
			WeightedTags.Add(Pair.Key);
		}
	}

	for (int i = 0; i < GridXSize; ++i)
	{
		for (int j = 0; j < GridYSize; ++j)
		{
			FVector Location = FVector(173.2f * i, 150.f * j, 0.f);
			if (j % 2 == 0)
			{
				Location += FVector(86.6f, 0.f, 0.f);
			}

			ATrcgTile* Tile = Cast<ATrcgTile>(GetWorld()->SpawnActor(TileClass));
			if (!Tile) continue;

			Tile->SetActorLocation(Location);
			Tile->Coords = {i, j};
			
			const int32 RandIndex = FMath::RandRange(0, WeightedTags.Num() - 1);
			Tile->TileTags.AddTag(WeightedTags[RandIndex]);
			
			Tiles.Add(Tile);
		}
	}
}


ATrcgTile* ATrcgTileManager::GetTileAtIndex(const int32 Index) const
{
	return Tiles[Index];
}

TArray<ATrcgTile*> ATrcgTileManager::GetNeighbourTiles(const int32 Index)
{
	TArray<ATrcgTile*> Neighbours;

	if (!Tiles.IsValidIndex(Index))
	{
		return Neighbours;
	}

	const FIntPoint Center = Tiles[Index]->Coords;
	const int X = Center.X;
	const int Y = Center.Y;

	const TArray<FIntPoint> DirectionsEven = {
		{+1, 0}, {0, -1}, {-1, -1},
		{-1, 0}, {-1, +1}, {0, +1}
	};
	const TArray<FIntPoint> DirectionsOdd = {
		{+1, 0}, {+1, -1}, {0, -1},
		{-1, 0}, {0, +1}, {+1, +1}
	};

	for (const TArray<FIntPoint>& Directions = (Y % 2 != 0) ? DirectionsEven : DirectionsOdd; const FIntPoint& Offset :
	     Directions)
	{
		const FIntPoint NeighbourCoords = FIntPoint(X + Offset.X, Y + Offset.Y);

		for (ATrcgTile* Tile : Tiles)
		{
			if (Tile->Coords == NeighbourCoords)
			{
				Neighbours.Add(Tile);
				break;
			}
		}
	}

	return Neighbours;
}

bool ATrcgTileManager::HasNeighbourTilesWithTileTag(const int32 Index, const FGameplayTag Tag)
{
	for (const ATrcgTile* Tile : GetNeighbourTiles(Index))
	{
		if (Tile->TileTags.HasTagExact(Tag)) return true;
	}
	return false;
}

bool ATrcgTileManager::AllHaveTileTag(const FGameplayTag Tag)
{
	for (const ATrcgTile* Tile : Tiles)
	{
		if (!Tile->TileTags.HasTagExact(Tag)) return false;
	}
	return true;
}
