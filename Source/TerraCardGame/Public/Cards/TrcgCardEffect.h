// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "General/TrcgObject.h"
#include "TrcgCardEffect.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TERRACARDGAME_API UTrcgCardEffect : public UTrcgObject
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "TRCG")
	void StartEffect();
};
