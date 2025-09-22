// Copyright Epic Games, Inc. All Rights Reserved.

#include "CategoryPrioritization.h"

#include "ObjectDetailCustomizationOverride.h"

#define LOCTEXT_NAMESPACE "FCategoryPrioritizationModule"

void FCategoryPrioritizationModule::StartupModule()
{
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	const FName& ObjectClassName = UObject::StaticClass()->GetFName();
	FDetailLayoutCallback const& ObjectDetailLayoutCallback = PropertyModule.GetClassNameToDetailLayoutNameMap().FindChecked(ObjectClassName);
	PropertyModule.RegisterCustomClassLayout(
		ObjectClassName,
		FOnGetDetailCustomizationInstance::CreateLambda([=]() -> TSharedRef<IDetailCustomization>
		{
			return FObjectDetailCustomizationOverride::MakeInstance(ObjectDetailLayoutCallback.DetailLayoutDelegate);
		}), 
		FRegisterCustomClassLayoutParams(ObjectDetailLayoutCallback.Order));
}

void FCategoryPrioritizationModule::ShutdownModule()
{
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	PropertyModule.UnregisterCustomClassLayout(UObject::StaticClass()->GetFName());
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCategoryPrioritizationModule, CategoryPrioritization)