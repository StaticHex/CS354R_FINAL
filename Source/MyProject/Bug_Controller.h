// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Proc_bug.h"
#include "Bug_Controller.generated.h"

UCLASS()
class MYPROJECT_API ABug_Controller : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABug_Controller();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

private:
	float generateX(float oldUsedX);

	float generateY(float oldUsedY);

	bool isUsed(TArray<float> &oldArray, float numCheck);

	float distanceBetween(float inOne, float inTwo);

	bool isOneGreater(float inOne, float inTwo);

	TArray<float> oldX;

	TArray<float> oldY;

	float newX;

	float newY;

	const int Array_size = 500;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Tarantula")
	TSubclassOf<AProc_bug> tarantula;

	UPROPERTY(EditDefaultsOnly, Category = "Stag Beetle")
	TSubclassOf<AProc_bug> stagBeetle;

	UPROPERTY(EditDefaultsOnly, Category = "Scorpion")
	TSubclassOf<AProc_bug> scorpion;

	UPROPERTY(EditDefaultsOnly, Category = "Tree")
	TSubclassOf<AProc_bug> tree;

	UPROPERTY(EditDefaultsOnly, Category = "Fire Fly")
	TSubclassOf<AProc_bug> firefly;

	UPROPERTY(EditDefaultsOnly, Category = "Gold Elephant beetle")
	TSubclassOf<AProc_bug> geBeetle;
	
};
