// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/TrcgTileManager.h"

#include "World/TrcgTile.h"


// Sets default values
ATrcgTileManager::ATrcgTileManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATrcgTileManager::GenerateGrid(TSet<FGameplayTag> DefaultTags)
{
	if (IsValid(TileClass))
	{
		for (int i = 0; i < GridXSize; ++i)
		{
			for (int j = 0; j < GridYSize; ++j)
			{
				FVector Location = FVector(173.2 * i, 150 * j, 0);
				if (j % 2 == 0)
				{
					Location += FVector(86.6, 0, 0);
				}
				ATrcgTile* Tile = static_cast<ATrcgTile*>(GetWorld()->SpawnActor(TileClass));
				Tile->SetActorLocation(Location);
				Tile->Coords = {i, j};
				for (FGameplayTag Tag : DefaultTags)
				{
					Tile->TileTags.AddTag(Tag);
				}
				Tiles.Add(Tile);
			}
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
