// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatSpin.h"

// Sets default values
AFloatSpin::AFloatSpin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisibleMash = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TriPyramidMesh"));
	VisibleMash->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_TriPyramid.Shape_TriPyramid"));

	if (CubeVisualAsset.Succeeded())
	{
		VisibleMash->SetStaticMesh(CubeVisualAsset.Object);
		VisibleMash->SetRelativeLocation(FVector(0.0f, 0.0f, 00.0f));

	}
}

// Called when the game starts or when spawned
void AFloatSpin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatSpin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLoc = GetActorLocation();
	FRotator NewRot = GetActorRotation();

	float RunTime = GetGameTimeSinceCreation();
	float DeltaHgt = (FMath::Sin(RunTime + DeltaTime) - FMath::Sin(RunTime));
	//NewLoc.Z += DeltaHgt * 21.0f;
	NewLoc.Z += DeltaHgt * HoverVelocity;

	//float DeltaRot = DeltaTime * 63.0f;
	float DeltaRot = DeltaTime * RotVelocity;
	NewRot.Yaw += DeltaRot;
	SetActorLocationAndRotation(NewLoc, NewRot);

}

