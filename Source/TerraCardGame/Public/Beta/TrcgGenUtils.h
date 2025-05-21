// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TrcgGenUtils.generated.h"

/**
 * 
 */
UCLASS()
class TERRACARDGAME_API UTrcgGenUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "TRCG")
	static TArray<FVector> GenerateFibonacciSpherePoints(const int32 NumPoints, const float Radius);
};
