// Copyright Epic Games, Inc. All Rights Reserved.

#include "ObjectDetailCustomizationOverride.h"

#include "CategoryPrioritizationDeveloperSettings.h"
#include "DetailLayoutBuilder.h"

FObjectDetailCustomizationOverride::FObjectDetailCustomizationOverride(TSharedRef<IDetailCustomization> const& OriginObjectDetails)
{
	ObjectDetails = OriginObjectDetails;
}

TSharedRef<IDetailCustomization> FObjectDetailCustomizationOverride::MakeInstance(FOnGetDetailCustomizationInstance const& ObjectDetailLayoutDelegate)
{
	return MakeShareable(new FObjectDetailCustomizationOverride(ObjectDetailLayoutDelegate.Execute()));
}

void FObjectDetailCustomizationOverride::CustomizeDetails(IDetailLayoutBuilder& DetailLayout)
{
	TArray<FName> const& Categories = GetDefault<UCategoryPrioritizationDeveloperSettings>()->GetHighestCategories();
	for (const FName& CategoryName : Categories)
	{
		DetailLayout.EditCategory(CategoryName, FText::GetEmpty(), ECategoryPriority::Variable);
	}

	// PrioritizeCategory metadata does not work, so we have to do it manually here
	UClass* BaseClass = DetailLayout.GetBaseClass();
	TArray<FString> PriorityCategories;
	BaseClass->GetPrioritizeCategories(PriorityCategories);
	for (const FString& CategoryName : PriorityCategories)
	{
		DetailLayout.EditCategory(*CategoryName, FText::GetEmpty(), ECategoryPriority::Variable);
	}
	
	ObjectDetails->CustomizeDetails(DetailLayout);
}
