// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RPGCampComponent.generated.h"

UENUM()
enum class ERPGCampRelation : uint8
{
	Ally,
	Enemy,
};


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class RPG_API URPGCampComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	URPGCampComponent();

public:
	UFUNCTION(BlueprintPure, DisplayName = "GetRelationOf")
	ERPGCampRelation K2_GetRelationOf(const URPGCampComponent* Other) const;

public:
	ERPGCampRelation GetRelationOf(const URPGCampComponent& Other) const;

private:
	UPROPERTY(EditDefaultsOnly)
	int32 Camp;
	
};
