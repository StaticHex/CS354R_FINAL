// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "Bug_Controller.h"


// Sets default values
ABug_Controller::ABug_Controller()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	newX = 0.f;
	newY = 0.f;

	oldX.SetNum(Array_size);
	oldY.SetNum(Array_size);

}

// Called when the game starts or when spawned
void ABug_Controller::BeginPlay()
{
	Super::BeginPlay();

	for (int i = 0; i < Array_size; i++)
	{
		newX = generateX(newX);
		newY = generateX(newY);

		oldX[i] = newX;
		oldY[i] = newY;

		const UWorld* world = GetWorld();

		if (world) {
			FActorSpawnParameters spawnParams;
			spawnParams.Owner = this;
			spawnParams.Instigator = Instigator;

			FVector newVec;
			newVec.Set(newX, newY, 10.f);

			int32 num = FMath::RandRange(0, 5);

			if (num == 0)
				AActor* newActor = GetWorld()->SpawnActor<AProc_bug>(tarantula, newVec, FRotator::ZeroRotator, spawnParams);
			else if (num == 1) {
				AActor* newActor = GetWorld()->SpawnActor<AProc_bug>(stagBeetle, newVec, FRotator::ZeroRotator, spawnParams);
			}
			else if (num == 2) {
				AActor* newActor = GetWorld()->SpawnActor<AProc_bug>(scorpion, newVec, FRotator::ZeroRotator, spawnParams);
			}
			else if (num == 3) {
				AActor* newActor = GetWorld()->SpawnActor<AProc_bug>(firefly, newVec, FRotator::ZeroRotator, spawnParams);
			}
			else if (num == 4) {
				AActor* newActor = GetWorld()->SpawnActor<AProc_bug>(geBeetle, newVec, FRotator::ZeroRotator, spawnParams);
			}
			else 
				AActor* newActor = GetWorld()->SpawnActor<AProc_bug>(tree, newVec, FRotator::ZeroRotator, spawnParams);


		}
	}
	
}

// Called every frame
void ABug_Controller::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

float ABug_Controller::generateX(float oldUsedX) {
	float passBack = 0.f;

	passBack = FMath::RandRange(-20000, 20000);

	passBack = passBack + oldUsedX;

	if (passBack < -20000.f || passBack > 20000.f) {
		passBack = generateX(oldUsedX);
	}

	if (!isUsed(oldX, passBack)) {
		passBack = generateX(oldUsedX);
	}

	return passBack; 
}

float ABug_Controller::generateY(float oldUsedY) {
	float passBack = 0.f;

	passBack = FMath::RandRange(-20000, 20000);

	passBack = passBack + oldUsedY;

	if (passBack < -20000.f || passBack > 20000.f) {
		passBack = generateY(oldUsedY);
	}

	if (!isUsed(oldY, passBack)) {
		passBack = generateY(oldUsedY);
	}

	return passBack;
}

bool ABug_Controller::isUsed(TArray<float> &oldArray, float numCheck) {
	bool flag = true; 
	for (int i = 0; i < oldArray.Num(); i++)
		if (distanceBetween(oldArray[i], numCheck) < 50.f)
			flag = false;
	return flag;
}

float ABug_Controller::distanceBetween(float inOne, float inTwo) {
	float passBack = 0.f;
	bool flag = isOneGreater(inOne, inTwo);
	if (flag) passBack = inOne - inTwo;
	else passBack = inTwo - inOne;
	return passBack;
}

bool ABug_Controller::isOneGreater(float inOne, float inTwo) {
	bool flag = true; 
	if (inOne <= inTwo)
		flag = false;
	return flag;
}

