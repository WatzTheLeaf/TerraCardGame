// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TrcgGameMode.generated.h"

class UTrcgGameInstance;
/**
 * 
 */
UCLASS(Blueprintable)
class TERRACARDGAME_API ATrcgGameMode : public AGameModeBase
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle = "TRCG Instance", Category="TRCG"))
	UTrcgGameInstance* GetTrcgGameInstance() const;
};
