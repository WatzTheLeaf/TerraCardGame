// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "General/TrcgActor.h"
#include "TrcgTileManager.generated.h"

class ATrcgTile;

UCLASS(Blueprintable)
class TERRACARDGAME_API ATrcgTileManager : public ATrcgActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATrcgTileManager();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int GridXSize = 10;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int GridYSize = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ATrcgTile*> Tiles;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<ATrcgTile> TileClass;
};
