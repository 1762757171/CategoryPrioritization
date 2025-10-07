// Copyright Epic Games, Inc. All Rights Reserved.

#include "CategoryPrioritization.h"

#include "DetailCustomizations.h"
#include "ObjectDetailCustomizationOverride.h"

#define LOCTEXT_NAMESPACE "FCategoryPrioritizationModule"

void FCategoryPrioritizationModule::StartupModule()
{
	FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	const FName& ObjectClassName = UObject::StaticClass()->GetFName();
	if (FDetailLayoutCallback const* ObjectDetailLayoutCallback = PropertyEditorModule.GetClassNameToDetailLayoutNameMap().Find(ObjectClassName))
	{
		FDetailLayoutCallback const LayoutCallbackCopy = *ObjectDetailLayoutCallback;
		PropertyEditorModule.RegisterCustomClassLayout(
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