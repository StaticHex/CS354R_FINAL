// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Proc_bug.generated.h"

UCLASS()
class MYPROJECT_API AProc_bug : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProc_bug();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
