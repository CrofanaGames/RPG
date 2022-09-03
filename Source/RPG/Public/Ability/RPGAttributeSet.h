// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "RPGAttributeSet.generated.h"

#define OPS_ALL(Op) \
Op(HP); \
Op(MP); \
Op(MaxHP); \
Op(MaxMP); \
Op(ATK); \
Op(DEF); \
Op(SPD); \
Op(ASP);

/**
 * 
 */
UCLASS()
class RPG_API URPGAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
#define GAMEPLAYATTRIBUTE_VALUE_SETTER_RPG(PropertyName) \
FORCEINLINE void Set##PropertyName(float NewVal) \
{ \
	UAbilitySystemComponent* AbilityComp = CastChecked<UAbilitySystemComponent>(GetOuter()); \
	if (ensure(AbilityComp)) \
	{ \
		AbilityComp->SetNumericAttributeBase(Get##PropertyName##Attribute(), NewVal); \
	}; \
}

#define ATTRIBUTE_ACCESSORS(PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ThisClass, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER_RPG(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
	
	OPS_ALL(ATTRIBUTE_ACCESSORS);

#undef ATTRIBUTE_ACCESSORS
#undef GAMEPLAYATTRIBUTE_VALUE_SETTER_RPG

private:
	// Status
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	FGameplayAttributeData HP;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	FGameplayAttributeData MP;

	// Parameters
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	FGameplayAttributeData MaxHP;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	FGameplayAttributeData MaxMP;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	FGameplayAttributeData ATK;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	FGameplayAttributeData DEF;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	FGameplayAttributeData SPD;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	FGameplayAttributeData ASP;
	
};
