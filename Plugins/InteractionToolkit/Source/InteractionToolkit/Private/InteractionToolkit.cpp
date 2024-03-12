// Copyright Epic Games, Inc. All Rights Reserved.

#include "InteractionToolkit.h"

#define LOCTEXT_NAMESPACE "FInteractionToolkitModule"

//implement constructor to register with OpenXR
FInteractionToolkitModule::FInteractionToolkitModule()
{
	// Register with OpenXR
}

void FInteractionToolkitModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	IModularFeatures::Get().RegisterModularFeature(IOpenXRExtensionPlugin::GetModularFeatureName(), this);

	
}

void FInteractionToolkitModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
}

static inline FInteractionToolkitModule& Get()
{
	return FModuleManager::LoadModuleChecked<FInteractionToolkitModule>("InteractionToolkit");
}

/**
* Checks to see if this module is loaded and ready.  It is only valid to call Get() if
* IsAvailable() returns true.
*
* @return True if the module is loaded and ready to use
*/
static inline bool IsAvailable()
{
	return FModuleManager::Get().IsModuleLoaded("InteractionToolkit");
}

void FInteractionToolkitModule::PostCreateInstance(XrInstance InInstance)
{
	Instance = InInstance;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FInteractionToolkitModule, InteractionToolkit)