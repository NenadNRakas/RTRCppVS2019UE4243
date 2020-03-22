// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatSpin.generated.h"

UCLASS()
class RENDERINGVR_API AFloatSpin : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatSpin();
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* VisibleMash;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FloatSpinActor")
		float HoverVelocity = 21.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FloatSpinActor")
		float RotVelocity = 63.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
