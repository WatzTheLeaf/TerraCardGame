#pragma once

#include "CoreMinimal.h"
#include "General/TrcgActor.h"
#include "VoronoiSphereActor.generated.h"

class AVoronoiTestCellActor;

UCLASS(Blueprintable)
class TERRACARDGAME_API AVoronoiSphereActor : public ATrcgActor
{
	GENERATED_BODY()

public:
	AVoronoiSphereActor();

protected:
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(EditAnywhere, Category = "TRCG")
	int32 NumPoints = 100;

	UPROPERTY(EditAnywhere, Category = "TRCG")
	float SphereRadius = 300.0f;

	UPROPERTY(EditAnywhere, Category = "TRCG", meta=(ClampMin=1, ClampMax=5))
	int32 MinLinks = 1;

	UPROPERTY(EditAnywhere, Category = "TRCG", meta=(ClampMin=3, ClampMax=10))
	int32 MaxLinks = 10;

	UPROPERTY(EditAnywhere, Category = "TRCG")
	int32 Seed = 0;
	
};
