// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Enums/ECardType.h"
#include "TrcgCardData.generated.h"

class UTrcgCardEffect;
/**
 * 
 */
UCLASS(BlueprintType)
class TERRACARDGAME_API UTrcgCardData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText CardName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ECardType CardType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTrcgCardEffect* CardEffect;
};
