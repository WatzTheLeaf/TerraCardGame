// Fill out your copyright notice in the Description page of Project Settings.


#include "Beta/VoronoiCellActor.h"

AVoronoiCellActor::AVoronoiCellActor()
{
	PrimaryActorTick.bCanEverTick = false;
	CellMesh = CreateDefaultSubobject<UProceduralMeshComponent>("CellMesh");
	CellMesh->SetupAttachment(RootComponent);
}

void AVoronoiCellActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	GenerateCellMesh();
}

void AVoronoiCellActor::GenerateCellMesh() const
{
	TArray Vertices = {FVector(0,0,0),FVector(0,-100,0),FVector(0,100,0)};
	TArray Triangles = {0,1,2};
	const FVector N = FVector::CrossProduct(FVector(0,-100,0)-FVector(0,0,0), FVector(0,100,0) - FVector(0,0,0));
	TArray Normals = {N,N,N};
	TArray UVs= {FVector2d(0,0), FVector2d(1,0), FVector2d(0,1)};

	FLinearColor Color = FLinearColor::MakeRandomColor();
	
	CellMesh->CreateMeshSection_LinearColor(0, Vertices, Triangles, Normals, UVs, {Color,Color,Color}, {FProcMeshTangent(0,1,0),FProcMeshTangent(0,1,0),FProcMeshTangent(0,1,0)}, true);
}

