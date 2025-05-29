// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TrcgGameInstance.generated.h"

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
};
