// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "RPGAbilitySystemComponent.generated.h"

class URPGAttributeSet;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class RPG_API URPGAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	URPGAbilitySystemComponent();

	virtual void OnRegister() override;
	virtual void OnUnregister() override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

public:
	UFUNCTION(BlueprintPure, DisplayName = "GetAttributeSet")
	URPGAttributeSet* K2_GetAttributeSet() const { return GetAttributeSet(); }

	UFUNCTION(BlueprintCallable)
	void SetSPD(float Value) const;

public:
	URPGAttributeSet* GetAttributeSet() const { return AttributeSet; }

private:
	UPROPERTY(VisibleAnywhere, Instanced, Transient)
	URPGAttributeSet* AttributeSet;
	
};
