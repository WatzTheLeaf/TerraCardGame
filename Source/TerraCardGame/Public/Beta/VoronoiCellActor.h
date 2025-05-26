// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "General/TrcgActor.h"
#include "ProceduralMeshComponent.h"
#include "VoronoiCellActor.generated.h"

UCLASS(Blueprintable)
class TERRACARDGAME_API AVoronoiCellActor : public ATrcgActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AVoronoiCellActor();

	void OnConstruction(const FTransform& Transform) override;

	void GenerateCellMesh() const;

	UProceduralMeshComponent* CellMesh;

	
};
