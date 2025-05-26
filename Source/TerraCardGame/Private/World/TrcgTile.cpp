// Fill out your copyright notice in the Description page of Project Settings.


#include "World/TrcgTile.h"


// Sets default values
ATrcgTile::ATrcgTile()
{
	PrimaryActorTick.bCanEverTick = false;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tile Mesh"));
	Mesh->SetupAttachment(RootComponent);
}

