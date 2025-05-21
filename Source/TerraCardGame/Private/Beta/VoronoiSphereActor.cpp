#include "Beta/VoronoiSphereActor.h"

#include "Beta/TrcgGenUtils.h"
#include "Engine/World.h"

AVoronoiSphereActor::AVoronoiSphereActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AVoronoiSphereActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

#if WITH_EDITOR
	const TArray<FVector> Points = UTrcgGenUtils::GenerateFibonacciSpherePoints(NumPoints, SphereRadius);
	const FVector Origin = GetActorLocation();

	// Afficher les points
	for (const FVector& Point : Points)
	{
		DrawDebugPoint(GetWorld(), Origin + Point, 5.0f, FColor::Yellow, false, 10.0f);
	}

	// Relier chaque point à ses voisins les plus proches (approx. Voronoï edges)
	for (int32 i = 0; i < Points.Num(); ++i)
	{
		const FVector& P1 = Points[i];
		TArray<TPair<float, int32>> Distances;

		// Calcul des distances
		for (int32 j = 0; j < Points.Num(); ++j)
		{
			if (i == j) continue;
			float Dist = FVector::DistSquared(P1, Points[j]);
			Distances.Add(TPair<float, int32>(Dist, j));
		}

		// Trier pour trouver les plus proches voisins
		Distances.Sort([](const TPair<float, int32>& A, const TPair<float, int32>& B)
		{
			return A.Key < B.Key;
		});

		// Relier aux Rand N plus proches
		FMath::RandInit(Seed);
		for (int32 k = 0; k < FMath::Min(FMath::RandRange(MinLinks, MaxLinks), Distances.Num()); ++k)
		{
			const FVector& P2 = Points[Distances[k].Value];
			DrawDebugLine(GetWorld(), Origin + P1, Origin + P2, FColor::Cyan, false, 10.0f, 0, 1.5f);
		}
	}
#endif
}