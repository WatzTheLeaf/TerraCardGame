// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "Enums/ECardType.h"
#include "TrcgCardData.generated.h"

class USlateBrushAsset;
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (MultiLine = "True"))
	FText CardDesc;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ECardType CardType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UTrcgCardEffect> CardEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTagContainer Tags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UMaterialInstance* Material;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FLinearColor Color = FLinearColor::White;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FSlateBrush Aspect = FSlateBrush();
};
