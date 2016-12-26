// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Spawned_rain.h"
#include "RainGenerator.generated.h"

UCLASS()
class MYPROJECT_API ARainGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARainGenerator();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = "RainGenerator")
	void rainOrNah();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Rain Emitter")
		TSubclassOf<ASpawned_rain> rain;	
};
