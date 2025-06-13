#include "General/TrcgPawn.h"

#include "General/TrcgGameInstance.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ATrcgPawn::ATrcgPawn()
{
	PrimaryActorTick.bCanEverTick = true;
}

UTrcgGameInstance* ATrcgPawn::GetTrcgGameInstance() const
{
	UTrcgGameInstance* GI = Cast<UTrcgGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	check(GI);
	return GI;
}

