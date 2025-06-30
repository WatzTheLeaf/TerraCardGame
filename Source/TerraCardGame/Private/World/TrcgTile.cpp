// Fill out your copyright notice in the Description page of Project Settings.


#include "World/TrcgTile.h"

// Sets default values
ATrcgTile::ATrcgTile()
{
	PrimaryActorTick.bCanEverTick = false;
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tile Mesh"));
	RootComponent = Scene;
	Mesh->SetupAttachment(RootComponent);
}
