// Fill out your copyright notice in the Description page of Project Settings.


#include "General/TrcgUserWidget.h"

#include "Kismet/GameplayStatics.h"
#include "General/TrcgGameInstance.h"

UTrcgGameInstance* UTrcgUserWidget::GetTrcgGameInstance() const
{
	UTrcgGameInstance* GI = Cast<UTrcgGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	check(GI);
	return GI;
}
