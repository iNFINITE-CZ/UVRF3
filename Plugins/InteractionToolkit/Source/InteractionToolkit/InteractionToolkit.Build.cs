// Some copyright should be here...

using System.IO;
using UnrealBuildTool;

public class InteractionToolkit : ModuleRules
{
	public InteractionToolkit(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);


        PrivateIncludePaths.AddRange(
            new string[] {
                    Path.Combine(GetModuleDirectory("OpenXRHMD"), "Private"), // TODO: Adding private include path from other module
            }
        );


        PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
                "InputDevice",
                "InputCore",
                "HeadMountedDisplay",
                "OpenXRHMD",
                "OpenXRInput",
                "XRBase"
				// ... add private dependencies that you statically link with here ...	
			}
			);

        AddEngineThirdPartyPrivateStaticDependencies(Target, "OpenXR");


        DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
