// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "RPGAbility.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API URPGAbility : public UGameplayAbility
{
	GENERATED_BODY()

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

public:
	void HandleGameplayEvent(const FGameplayEventData& Payload);

private:
	UPROPERTY(EditDefaultsOnly)
	UAnimMontage* MontageToPlay;
	
};
