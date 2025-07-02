// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "General/TrcgActor.h"
#include "World/TrcgPlanetStat.h"
#include "TrcgPlanetStatsManager.generated.h"

class UTrcgPlanetStat;

UCLASS(Blueprintable)
class TERRACARDGAME_API ATrcgPlanetStatsManager : public ATrcgActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATrcgPlanetStatsManager();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TRCG")
	TArray<UTrcgPlanetStat*> Stats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TRCG")
	TArray<UTrcgPlanetStat*> Objectives;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="TRCG")
	TMap<TSubclassOf<UTrcgPlanetStat>, int> Preview;

	UFUNCTION(BlueprintPure, Category="TRCG")
	UTrcgPlanetStat* GetStatFromClass(const TSubclassOf<UTrcgPlanetStat> Class);

	UFUNCTION(BlueprintPure, Category="TRCG")
	bool HasActivePreview() const;
};
