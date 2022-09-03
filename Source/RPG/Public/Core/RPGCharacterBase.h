// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "Ability/InitialAbilityDef.h"
#include "GameFramework/Character.h"
#include "RPGCharacterBase.generated.h"

class URPGCampComponent;
class URPGAbilitySystemComponent;
class URPGAbility;

UCLASS()
class RPG_API ARPGCharacterBase : public ACharacter, public IAbilitySystemInterface, public IInitialAbilityDef
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARPGCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual TSet<TSubclassOf<URPGAbility>> GetInitialAbilities() const override { return InitialAbilities; }

	UFUNCTION(BlueprintPure)
	URPGCampComponent* GetCampComponent() const { return CampComponent; }

	UFUNCTION(BlueprintPure)
	URPGAbilitySystemComponent* GetRPGAbilitySystemComponent() const { return AbilitySystemComponent; }

private:
	UPROPERTY(VisibleAnywhere)
	URPGCampComponent* CampComponent;

	UPROPERTY(VisibleAnywhere)
	URPGAbilitySystemComponent* AbilitySystemComponent;

private:
	UPROPERTY(EditDefaultsOnly)
	TSet<TSubclassOf<URPGAbility>> InitialAbilities;
	
};
