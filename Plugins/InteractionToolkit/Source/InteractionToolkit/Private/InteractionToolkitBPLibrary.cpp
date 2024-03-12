// Copyright Epic Games, Inc. All Rights Reserved.

#include "InteractionToolkitBPLibrary.h"
#include "InteractionToolkit.h"
#include "OpenXRCore.h"
#include "Framework/Application/SlateApplication.h"
#include "IOpenXRExtensionPlugin.h"
#include "Modules/ModuleManager.h"
#include "Features/IModularFeatures.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "IOpenXRHMDModule.h"
#include "HeadMountedDisplayFunctionLibrary.h" // For VR functionalities
#include "IXRTrackingSystem.h" // For XR tracking system

UInteractionToolkitBPLibrary::UInteractionToolkitBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}


//implement get system name
FString UInteractionToolkitBPLibrary::GetOpenXRSystemSettings()
{

	static FName SystemName(TEXT("OpenXR"));
	IXRTrackingSystem* XRTrackingSystem = nullptr;
	if (GEngine->XRSystem.IsValid() && (GEngine->XRSystem->GetSystemName() == SystemName))
	{
		XRTrackingSystem = GEngine->XRSystem.Get();
	}
	else {
		return FString("No Tracking system");
	}
	
	//get module instance and xrinstance
	FInteractionToolkitModule& InteractionToolkitModule = FModuleManager::GetModuleChecked<FInteractionToolkitModule>("InteractionToolkit");
	XrInstance Instance = InteractionToolkitModule.Instance;
	
	//check if instance is valid
	if (Instance == XR_NULL_HANDLE)
	{
		return FString("Invalid xrInstance");
	}

	// Get System ID
	XrSystemId systemId = XR_NULL_SYSTEM_ID;
	XrSystemGetInfo systemGetInfo{ XR_TYPE_SYSTEM_GET_INFO };
	systemGetInfo.formFactor = XR_FORM_FACTOR_HEAD_MOUNTED_DISPLAY;
	XrResult result = xrGetSystem(Instance, &systemGetInfo, &systemId);

	if (XR_FAILED(result) || systemId == XR_NULL_SYSTEM_ID)
	{
		return FString("Failed to get System ID");
	}

	// Get System Properties
	XrSystemProperties systemProperties{ XR_TYPE_SYSTEM_PROPERTIES };
	result = xrGetSystemProperties(Instance, systemId, &systemProperties);

	if (XR_FAILED(result))
	{
		return FString("Failed to get System Properties");
	}

	// Construct a detailed string with system information
	FString Details;
	Details += FString::Printf(TEXT("System Name: %s\n"), UTF8_TO_TCHAR(systemProperties.systemName));
	Details += FString::Printf(TEXT("System ID: %llu\n"), systemId);
	Details += FString::Printf(TEXT("Vendor ID: %d\n"), systemProperties.vendorId);
	Details += FString::Printf(TEXT("Max Layers: %d\n"), systemProperties.graphicsProperties.maxLayerCount);
	Details += FString::Printf(TEXT("Position Tracking: %s\n"), systemProperties.trackingProperties.positionTracking ? TEXT("Yes") : TEXT("No"));
	Details += FString::Printf(TEXT("Orientation Tracking: %s"), systemProperties.trackingProperties.orientationTracking ? TEXT("Yes") : TEXT("No"));

	return Details;
}

//implement get openxr extensions
FString UInteractionToolkitBPLibrary::GetOpenXRExtensions()
{
	//get module instance and xrinstance
	FInteractionToolkitModule& InteractionToolkitModule = FModuleManager::GetModuleChecked<FInteractionToolkitModule>("InteractionToolkit");
	XrInstance Instance = InteractionToolkitModule.Instance;

	//check if instance is valid
	if (Instance == XR_NULL_HANDLE)
	{
		return FString("Invalid xrInstance");
	}

	// Get the number of extensions
	uint32_t extensionCount;
	XrResult result = xrEnumerateInstanceExtensionProperties(nullptr, 0, &extensionCount, nullptr);
	if (XR_FAILED(result))
	{
		return FString("Failed to get extension count");
	}

	// Get the extension properties
	TArray<XrExtensionProperties> extensionProperties;
	extensionProperties.SetNum(extensionCount, false);
	for (uint32_t i = 0; i < extensionCount; ++i)
	{
		extensionProperties[i].type = XR_TYPE_EXTENSION_PROPERTIES;
	}

	result = xrEnumerateInstanceExtensionProperties(nullptr, extensionCount, &extensionCount, extensionProperties.GetData());
	if (XR_FAILED(result))
	{
		return FString("Failed to get extension properties");
	}

	// Construct a detailed string with extension information
	FString Details;
	for (const XrExtensionProperties& extension : extensionProperties)
	{
		Details += FString::Printf(TEXT("%s\n"), UTF8_TO_TCHAR(extension.extensionName));
	}

	return Details;
}

//implement get input paths
FString UInteractionToolkitBPLibrary::GetOpenXRInputPaths()
{
	//get module instance and xrinstance
	FInteractionToolkitModule& InteractionToolkitModule = FModuleManager::GetModuleChecked<FInteractionToolkitModule>("InteractionToolkit");
	XrInstance Instance = InteractionToolkitModule.Instance;

	//check if instance is valid
	if (Instance == XR_NULL_HANDLE)
	{
		return FString("Invalid xrInstance");
	}

	return FString("Not implemented yet");	

}