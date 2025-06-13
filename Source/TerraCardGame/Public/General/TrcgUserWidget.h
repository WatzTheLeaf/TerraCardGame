// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TrcgUserWidget.generated.h"

class UTrcgGameInstance;
/**
 * 
 */
UCLASS()
class TERRACARDGAME_API UTrcgUserWidget : public UUserWidget
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle = "TRCG Instance", Category="TRCG"))
	UTrcgGameInstance* GetTrcgGameInstance() const;
};
