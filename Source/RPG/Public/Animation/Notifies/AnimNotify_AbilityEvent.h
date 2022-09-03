// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "GameplayTagContainer.h"
#include "AnimNotify_AbilityEvent.generated.h"

/**
 * 
 */
UCLASS(DisplayName = "Trigger Ability Event")
class RPG_API UAnimNotify_AbilityEvent : public UAnimNotify
{
	GENERATED_BODY()

	static FString Prefix;

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

#if WITH_EDITOR
	virtual FString GetNotifyName_Implementation() const override
	{
		if (IsValid())
		{
			return EventTag.ToString().RightChop(Prefix.Len());
		}
		else
		{
			return FString::Printf(TEXT("%s (invalid)"), *EventTag.ToString());
		}
	}
#endif

private:
	bool IsValid() const
	{
		return EventTag.ToString().StartsWith("Ability.Event.");
	}

	UPROPERTY(EditAnywhere)
	FGameplayTag EventTag;
	
};

inline FString UAnimNotify_AbilityEvent::Prefix = TEXT("Ability.Event.");