// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "General/TrcgObject.h"
#include "TrcgPlanetStat.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TERRACARDGAME_API UTrcgPlanetStat : public UTrcgObject
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TRCG")
	FText Name = FText::GetEmpty();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TRCG", meta = (ClampMin = 0, ClampMax = 20, UIMin = 0, UIMax = 20))
	int Value = 0;
};
