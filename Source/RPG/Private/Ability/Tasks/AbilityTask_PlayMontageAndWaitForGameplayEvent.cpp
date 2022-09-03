// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability/Tasks/AbilityTask_PlayMontageAndWaitForGameplayEvent.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"
#include "Ability/Abilities/RPGAbility.h"

UAbilityTask_PlayMontageAndWaitForGameplayEvent* UAbilityTask_PlayMontageAndWaitForGameplayEvent::New(UGameplayAbility* OwningAbility,
	FName TaskInstanceName, UAnimMontage* InMontageToPlay, const FGameplayTagContainer& InEventTags, float InRate, FName InStartSection, bool bInStopWhenAbilityEnds,
	float InAnimRootMotionTranslationScale, float InStartTimeSeconds)
{
	UAbilitySystemGlobals::NonShipping_ApplyGlobalAbilityScaler_Rate(InRate);

	UAbilityTask_PlayMontageAndWaitForGameplayEvent* MyObj = NewAbilityTask<UAbilityTask_PlayMontageAndWaitForGameplayEvent>(OwningAbility, TaskInstanceName);
	MyObj->MontageToPlay = InMontageToPlay;
	MyObj->EventTags = InEventTags;
	MyObj->Rate = InRate;
	MyObj->StartSection = InStartSection;
	MyObj->AnimRootMotionTranslationScale = InAnimRootMotionTranslationScale;
	MyObj->bStopWhenAbilityEnds = bInStopWhenAbilityEnds;
	MyObj->StartTimeSeconds = InStartTimeSeconds;
	
	return MyObj;
}

void UAbilityTask_PlayMontageAndWaitForGameplayEvent::Activate()
{
	Super::Activate();

	if (AbilitySystemComponent)
	{
		GameplayEventDelegate = AbilitySystemComponent->AddGameplayEventTagContainerDelegate(EventTags, FGameplayEventTagMulticastDelegate::FDelegate::CreateWeakLambda(this, [this](FGameplayTag EventTag, const FGameplayEventData* Payload)
		{
			check(Payload);
			check(EventTag == Payload->EventTag);
			if (URPGAbility* RPGAbility = CastChecked<URPGAbility>(Ability))
			{
				RPGAbility->HandleGameplayEvent(*Payload);
			}
		}));
	}
}

void UAbilityTask_PlayMontageAndWaitForGameplayEvent::OnDestroy(bool bInOwnerFinished)
{
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->RemoveGameplayEventTagContainerDelegate(EventTags, GameplayEventDelegate);
	}
	
	Super::OnDestroy(bInOwnerFinished);
}
