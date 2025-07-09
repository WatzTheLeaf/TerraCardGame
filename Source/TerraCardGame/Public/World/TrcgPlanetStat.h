// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "General/TrcgObject.h"
#include "Enums/EStatCheckType.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TRCG", meta = (ExposeOnSpawn))
	int Value = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "TRCG")
	EStatCheckType CheckRule = EStatCheckType::EQUALTO;

	UFUNCTION(BlueprintCallable, Category = "TRCG")
	void ApplyStatChange(const int Change);
};
