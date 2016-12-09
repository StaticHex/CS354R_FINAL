// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "RainGenerator.h"


// Sets default values
ARainGenerator::ARainGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARainGenerator::BeginPlay()
{
	Super::BeginPlay();
	const UWorld* world = GetWorld();

	if (world) {
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j)
			{
				FActorSpawnParameters spawnParams;
				spawnParams.Owner = this;
				spawnParams.Instigator = Instigator;

				FVector newVec;
				newVec.Set(1000.f * i, 1000.f * j, 0.f);

				AActor* newActor = GetWorld()->SpawnActor<ASpawned_rain>(rain, newVec, FRotator::ZeroRotator, spawnParams);
			}
		}
	}
	
}

// Called every frame
void ARainGenerator::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ARainGenerator::rainOrNah() {

}

