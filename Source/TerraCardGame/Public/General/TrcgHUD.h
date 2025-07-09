// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TrcgHUD.generated.h"

class UTrcgUserWidget;
class UTrcgGameInstance;
/**
 * 
 */
UCLASS()
class TERRACARDGAME_API ATrcgHUD : public AHUD
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle = "TRCG Instance", Category="TRCG"))
	UTrcgGameInstance* GetTrcgGameInstance() const;

	UFUNCTION(BlueprintCallable, Category = "TRCG")
	UTrcgUserWidget* GetWidgetFromClass(const TSubclassOf<UTrcgUserWidget> Class);

public:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "TRCG")
	TArray<UTrcgUserWidget*> ActiveWidgets;
};
