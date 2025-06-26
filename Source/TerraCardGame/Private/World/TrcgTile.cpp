// Fill out your copyright notice in the Description page of Project Settings.


#include "World/TrcgTile.h"

#include "General/TrcgGameInstance.h"
#include "Manager/TrcgTileManager.h"


// Sets default values
ATrcgTile::ATrcgTile()
{
	PrimaryActorTick.bCanEverTick = false;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tile Mesh"));
	Mesh->SetupAttachment(RootComponent);
}
