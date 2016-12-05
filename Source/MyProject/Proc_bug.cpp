// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "Proc_bug.h"


// Sets default values
AProc_bug::AProc_bug()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProc_bug::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProc_bug::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

