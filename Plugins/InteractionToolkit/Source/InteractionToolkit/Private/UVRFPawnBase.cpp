// Fill out your copyright notice in the Description page of Project Settings.


#include "UVRFPawnBase.h"

// Sets default values
AUVRFPawnBase::AUVRFPawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WidgetPointerId = 10;

}

// Called when the game starts or when spawned
void AUVRFPawnBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUVRFPawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AUVRFPawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

int AUVRFPawnBase::RegisterWidgetInteract()
{
	return ++WidgetPointerId;
}

