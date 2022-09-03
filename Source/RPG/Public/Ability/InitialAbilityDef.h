// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InitialAbilityDef.generated.h"

class URPGAbility;

UINTERFACE()
class UInitialAbilityDef : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class RPG_API IInitialAbilityDef : public IInterface
{
	GENERATED_BODY()

public:
	virtual TSet<TSubclassOf<URPGAbility>> GetInitialAbilities() const = 0;
};
