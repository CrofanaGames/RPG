// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability/Abilities/RPGAbility.h"

#include "Ability/Tasks/AbilityTask_PlayMontageAndWaitForGameplayEvent.h"

void URPGAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	if (!MontageToPlay)
	{
		EndAbility(Handle, ActorInfo, ActivationInfo, false, true);
	}
	
	UAbilityTask_PlayMontageAndWaitForGameplayEvent* Task = UAbilityTask_PlayMontageAndWaitForGameplayEvent::New(
		this,
		NAME_None,
		MontageToPlay
		);

	Task->OnCompleted.AddDynamic(this, &ThisClass::K2_EndAbility);
	Task->OnInterrupted.AddDynamic(this, &ThisClass::K2_CancelAbility);
	Task->OnCancelled.AddDynamic(this, &ThisClass::K2_CancelAbility);

	Task->ReadyForActivation();
}

void URPGAbility::HandleGameplayEvent(const FGameplayEventData& Payload)
{
	UE_LOG(LogTemp, Warning, TEXT("[URPGAbility::HandleGameplayEvent] Tag: %s"), *Payload.EventTag.ToString());
}
