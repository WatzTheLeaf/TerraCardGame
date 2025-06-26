// Fill out your copyright notice in the Description page of Project Settings.


#include "World/TrcgPlanetStat.h"

void UTrcgPlanetStat::ApplyStatChange(const int Change)
{
	Value = FMath::Clamp(Value + Change, 0, 20);
}
