// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "IDetailCustomization.h"

class FObjectDetailCustomizationOverride : public IDetailCustomization
{
public:
	FObjectDetailCustomizationOverride(TSharedRef<IDetailCustomization> const& OriginObjectDetails);
	
	static TSharedRef<IDetailCustomization> MakeInstance(FOnGetDetailCustomizationInstance const& ObjectDetailLayoutDelegate);

protected:
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailLayout) override;

private:
	TSharedPtr<IDetailCustomization> ObjectDetails;

};
