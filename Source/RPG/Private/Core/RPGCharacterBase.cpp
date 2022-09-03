// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/RPGCharacterBase.h"

#include "Ability/RPGAbilitySystemComponent.h"
#include "Camp/RPGCampComponent.h"

ARPGCharacterBase::ARPGCharacterBase()
{
	CampComponent = CreateDefaultSubobject<URPGCampComponent>("CampComponent");
	AbilitySystemComponent = CreateDefaultSubobject<URPGAbilitySystemComponent>("AbilitySystemComponent");
}

// Called when the game starts or when spawned
void ARPGCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARPGCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

UAbilitySystemComponent* ARPGCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
