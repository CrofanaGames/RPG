// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability/RPGAbilitySystemComponent.h"

#include "Ability/InitialAbilityDef.h"
#include "Ability/RPGAttributeSet.h"
#include "Ability/Abilities/RPGAbility.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values for this component's properties
URPGAbilitySystemComponent::URPGAbilitySystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	AttributeSet = CreateDefaultSubobject<URPGAttributeSet>("AttributeSet");
	AddAttributeSetSubobject(AttributeSet);

	GetGameplayAttributeValueChangeDelegate(AttributeSet->GetSPDAttribute()).AddWeakLambda(this, [this](const FOnAttributeChangeData& Data)
	{
		if (const ACharacter* OwnerCharacter = GetOwner<ACharacter>())
		{
			if (UCharacterMovementComponent* CMC = OwnerCharacter->GetCharacterMovement())
			{
				CMC->MaxWalkSpeed = Data.NewValue;
			}
		}
	});
}

void URPGAbilitySystemComponent::OnRegister()
{
	Super::OnRegister();

	if (const IInitialAbilityDef* InitialAbilityDef = Cast<IInitialAbilityDef>(GetOwner()))
	{
		TSet<TSubclassOf<URPGAbility>> InitialAbilities = InitialAbilityDef->GetInitialAbilities();
		for (auto InitialAbility : InitialAbilities)
		{
			GiveAbility(FGameplayAbilitySpec(InitialAbility));
		}
	}
}

void URPGAbilitySystemComponent::OnUnregister()
{
	ClearAllAbilities();
	
	Super::OnUnregister();
}


// Called when the game starts
void URPGAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();

	AttributeSet->SetMaxHP(100.f);
	AttributeSet->SetATK(10.f);
	AttributeSet->SetHP(AttributeSet->GetMaxHP());
}


// Called every frame
void URPGAbilitySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                               FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void URPGAbilitySystemComponent::SetSPD(float Value) const
{
	AttributeSet->SetSPD(Value);
}

