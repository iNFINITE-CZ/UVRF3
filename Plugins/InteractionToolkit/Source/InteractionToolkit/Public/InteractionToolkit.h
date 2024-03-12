// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "IOpenXRExtensionPlugin.h"
#include "Modules/ModuleManager.h"

class FInteractionToolkitModule : public IOpenXRExtensionPlugin, public IModuleInterface
{
public:

	// add construcotr
	FInteractionToolkitModule();
	

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	virtual void PostCreateInstance(XrInstance InInstance) override;



public:
	class IXRTrackingSystem* XRTrackingSystem = nullptr;
	XrInstance Instance = XR_NULL_HANDLE;

};
