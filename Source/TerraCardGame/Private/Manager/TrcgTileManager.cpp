// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/TrcgTileManager.h"

#include "World/TrcgTile.h"


// Sets default values
ATrcgTileManager::ATrcgTileManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATrcgTileManager::GenerateGrid() const
{
	if (IsValid(TileClass))
	{
		for (int i = 0; i < GridXSize; ++i)
		{
			for (int j = 0; j < GridYSize; ++j)
			{
				FVector Location = FVector(173.2*i, 150*j, 0);
				if (j % 2 == 0)
				{
					Location += FVector(86.6, 0, 0);
				}
				ATrcgTile* Tile = static_cast<ATrcgTile*>(GetWorld()->SpawnActor(TileClass));
				Tile->SetActorLocation(Location);
			}
		}
	}
}
