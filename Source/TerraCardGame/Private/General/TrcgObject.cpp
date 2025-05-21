// Fill out your copyright notice in the Description page of Project Settings.


#include "TerraCardGame/Public/General/TrcgObject.h"

#include "Kismet/GameplayStatics.h"
#include "TerraCardGame/Public/General/TrcgGameInstance.h"

UTrcgGameInstance* UTrcgObject::GetTrcgGameInstance() const
{
	UTrcgGameInstance* GI = Cast<UTrcgGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	check(GI);
	return GI;
}
