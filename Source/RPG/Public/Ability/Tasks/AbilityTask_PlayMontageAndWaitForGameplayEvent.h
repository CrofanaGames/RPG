// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask_PlayMontageAndWait.h"
#include "AbilityTask_PlayMontageAndWaitForGameplayEvent.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API UAbilityTask_PlayMontageAndWaitForGameplayEvent : public UAbilityTask_PlayMontageAndWait
{
	GENERATED_BODY()

public:
	/** 
 	 * Start playing an animation montage on the avatar actor and wait for it to finish
 	 * If StopWhenAbilityEnds is true, this montage will be aborted if the ability ends normally. It is always stopped when the ability is explicitly cancelled.
 	 * On normal execution, OnBlendOut is called when the montage is blending out, and OnCompleted when it is completely done playing
 	 * OnInterrupted is called if another montage overwrites this, and OnCancelled is called if the ability or task is cancelled
 	 *
 	 * @param TaskInstanceName Set to override the name of this task, for later querying
 	 * @param MontageToPlay The montage to play on the character
 	 * @param Rate Change to play the montage faster or slower
 	 * @param StartSection If not empty, named montage section to start from
 	 * @param bStopWhenAbilityEnds If true, this montage will be aborted if the ability ends normally. It is always stopped when the ability is explicitly cancelled
 	 * @param AnimRootMotionTranslationScale Change to modify size of root motion or set to 0 to block it entirely
 	 * @param StartTimeSeconds Starting time offset in montage, this will be overridden by StartSection if that is also set
 	 */
	UFUNCTION(BlueprintCallable, Category="Ability|Tasks", meta = (DisplayName="PlayMontageAndWait",
		HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "TRUE"))
	static UAbilityTask_PlayMontageAndWaitForGameplayEvent* New(UGameplayAbility* OwningAbility,
		FName TaskInstanceName, UAnimMontage* InMontageToPlay, const FGameplayTagContainer& EventTags = FGameplayTagContainer(), float InRate = 1.f, FName InStartSection = NAME_None, bool bInStopWhenAbilityEnds = true, float InAnimRootMotionTranslationScale = 1.f, float InStartTimeSeconds = 0.f);


	virtual void Activate() override;
	virtual void OnDestroy(bool bInOwnerFinished) override;

private:
	FGameplayTagContainer EventTags;
	FDelegateHandle GameplayEventDelegate;
	
};
