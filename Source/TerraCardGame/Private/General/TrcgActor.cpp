// Fill out your copyright notice in the Description page of Project Settings.


#include "TerraCardGame/Public/General/TrcgActor.h"

#include "Kismet/GameplayStatics.h"
#include "TerraCardGame/Public/General/TrcgGameInstance.h"


// Sets default values
ATrcgActor::ATrcgActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

UTrcgGameInstance* ATrcgActor::GetTrcgGameInstance() const
{
	UTrcgGameInstance* GI = Cast<UTrcgGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	check(GI);
	return GI;
}

