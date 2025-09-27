// Copyright Epic Games, Inc. All Rights Reserved.

#include "CategoryPrioritization.h"

#include "ObjectDetailCustomizationOverride.h"

#define LOCTEXT_NAMESPACE "FCategoryPrioritizationModule"

void FCategoryPrioritizationModule::StartupModule()
{
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	const FName& ObjectClassName = UObject::StaticClass()->GetFName();
	if (FDetailLayoutCallback const* ObjectDetailLayoutCallback = PropertyModule.GetClassNameToDetailLayoutNameMap().Find(ObjectClassName))
	{
		FDetailLayoutCallback const LayoutCallbackCopy = *ObjectDetailLayoutCallback;
		PropertyModule.RegisterCustomClassLayout(
			ObjectClassName,
			FOnGetDetailCustomizationInstance::CreateLambda([=]() -> TSharedRef<IDetailCustomization>
			{
				return FObjectDetailCustomizationOverride::MakeInstance(LayoutCallbackCopy.DetailLayoutDelegate);
			}), 
			FRegisterCustomClassLayoutParams(LayoutCallbackCopy.Order));
	}
}

void FCategoryPrioritizationModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCategoryPrioritizationModule, CategoryPrioritization)