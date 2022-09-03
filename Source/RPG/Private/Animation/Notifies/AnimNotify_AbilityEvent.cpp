// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/Notifies/AnimNotify_AbilityEvent.h"
#include "Animation/DebugSkelMeshComponent.h"

#include "AbilitySystemBlueprintLibrary.h"

void UAnimNotify_AbilityEvent::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (!MeshComp)
	{
		return;
	}

#if WITH_EDITOR
	if (!MeshComp->IsA<UDebugSkelMeshComponent>())
#endif
	{
		ensureMsgf(IsValid(), TEXT("[UAnimNotify_AbilityEvent::Notify] Invalid tag: %s"), *EventTag.ToString());
	}

	if (AActor* OwnerActor = MeshComp->GetOwner())
	{
		FGameplayEventData Payload;
		Payload.EventTag = EventTag;
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(OwnerActor, EventTag, Payload);
	}
}
