// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FCategoryPrioritizationModule : public IModuleInterface
{
protected:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
};
