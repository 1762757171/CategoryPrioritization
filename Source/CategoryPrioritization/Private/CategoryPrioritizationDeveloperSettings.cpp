// Fill out your copyright notice in the Description page of Project Settings.


#include "CategoryPrioritizationDeveloperSettings.h"

UCategoryPrioritizationDeveloperSettings::UCategoryPrioritizationDeveloperSettings()
{
	SectionName = TEXT("Category Prioritization");
}

FName UCategoryPrioritizationDeveloperSettings::GetContainerName() const
{
	return NAME_Editor;
}

FName UCategoryPrioritizationDeveloperSettings::GetCategoryName() const
{
	return TEXT("General");
}

FName UCategoryPrioritizationDeveloperSettings::GetSectionName() const
{
	return SectionName;
}

#if WITH_EDITOR
FText UCategoryPrioritizationDeveloperSettings::GetSectionText() const
{
	return FText::FromName(SectionName);
}
#endif

TArray<FName> const& UCategoryPrioritizationDeveloperSettings::GetHighestCategories() const
{
	return HighestCategories;
}
