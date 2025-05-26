// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "General/TrcgActor.h"
#include "TrcgTile.generated.h"

UCLASS(Blueprintable)
class TERRACARDGAME_API ATrcgTile : public ATrcgActor
{
	GENERATED_BODY()

public:
	ATrcgTile();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TRCG")
	UStaticMeshComponent* Mesh;
};
