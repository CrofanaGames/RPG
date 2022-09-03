// Fill out your copyright notice in the Description page of Project Settings.


#include "Camp/RPGCampComponent.h"

URPGCampComponent::URPGCampComponent()
{
	
}

ERPGCampRelation URPGCampComponent::K2_GetRelationOf(const URPGCampComponent* Other) const
{
	return Other ? GetRelationOf(*Other) : ERPGCampRelation::Enemy;
}

ERPGCampRelation URPGCampComponent::GetRelationOf(const URPGCampComponent& Other) const
{
	return Camp == Other.Camp ? ERPGCampRelation::Ally : ERPGCampRelation::Enemy;
}

