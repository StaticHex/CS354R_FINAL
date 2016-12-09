// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "Spawned_rain.h"


// Sets default values
ASpawned_rain::ASpawned_rain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawned_rain::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawned_rain::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

