// Fill out your copyright notice in the Description page of Project Settings.


#include "TerraCardGame/Public/General/TrcgGameMode.h"

#include "General/TrcgGameInstance.h"
#include "Kismet/GameplayStatics.h"

UTrcgGameInstance* ATrcgGameMode::GetTrcgGameInstance() const
{
	UTrcgGameInstance* GI = Cast<UTrcgGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	check(GI);
	return GI;
}
