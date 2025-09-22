// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "CategoryPrioritizationDeveloperSettings.generated.h"

UCLASS(Config = EditorPerProjectUserSettingsName, DefaultConfig)
class CATEGORYPRIORITIZATION_API UCategoryPrioritizationDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UCategoryPrioritizationDeveloperSettings();

	virtual FName GetContainerName() const override;
	virtual FName GetCategoryName() const override;
	virtual FName GetSectionName() const override;
#if WITH_EDITOR
	virtual FText GetSectionText() const override;
#endif

	TArray<FName> const& GetHighestCategories() const;

private:
	UPROPERTY(EditAnywhere, Category = "Category Prioritization")
	TArray<FName> HighestCategories;
	
};
