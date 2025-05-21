// Fill out your copyright notice in the Description page of Project Settings.


#include "Beta/TrcgGenUtils.h"

TArray<FVector> UTrcgGenUtils::GenerateFibonacciSpherePoints(const int32 NumPoints, const float Radius)
{
	TArray<FVector> Points;
	const float GoldenRatio = (1 + FMath::Sqrt(5.0f)) / 2;
	const float AngleIncrement = 2 * PI * GoldenRatio;

	for (int32 i = 0; i < NumPoints; ++i)
	{
		float t = static_cast<float>(i) / static_cast<float>(NumPoints - 1);
		float inclination = FMath::Acos(1 - 2 * t);
		float azimuth = AngleIncrement * i;

		float x = FMath::Sin(inclination) * FMath::Cos(azimuth);
		float y = FMath::Sin(inclination) * FMath::Sin(azimuth);
		float z = FMath::Cos(inclination);

		Points.Add(FVector(x, y, z) * Radius);
	}
	return Points;
}

