// Fill out your copyright notice in the Description page of Project Settings.


#include "General/TrcgHUD.h"

#include "General/TrcgGameInstance.h"
#include "General/TrcgUserWidget.h"
#include "Kismet/GameplayStatics.h"

UTrcgGameInstance* ATrcgHUD::GetTrcgGameInstance() const
{
	UTrcgGameInstance* GI = Cast<UTrcgGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	check(GI);
	return GI;
}

UTrcgUserWidget* ATrcgHUD::GetWidgetFromClass(const TSubclassOf<UTrcgUserWidget> Class)
{
	for (UTrcgUserWidget* Widget : ActiveWidgets)
	{
		if (Widget->GetClass() == Class) return Widget;
	}
	return nullptr;
}
