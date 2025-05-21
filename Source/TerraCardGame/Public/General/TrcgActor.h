// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TrcgActor.generated.h"

class UTrcgGameInstance;

UCLASS()
class TERRACARDGAME_API ATrcgActor : public AActor
{
	GENERATED_BODY()

public:

	ATrcgActor();
	
	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle = "TRCG Instance", Category="TRCG"))
	UTrcgGameInstance* GetTrcgGameInstance() const;
	
};
