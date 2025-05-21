// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TrcgObject.generated.h"

class UTrcgGameInstance;
/**
 * 
 */
UCLASS(Blueprintable)
class TERRACARDGAME_API UTrcgObject : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle = "TRCG Instance", Category="TRCG"))
	UTrcgGameInstance* GetTrcgGameInstance() const;
	
};
