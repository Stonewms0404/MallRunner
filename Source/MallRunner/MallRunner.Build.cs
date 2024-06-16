// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MallRunner : ModuleRules
{
	public MallRunner(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "EnhancedInput",
            "HeadMountedDisplay",
            "AIModule",
            "GameplayTasks",
            "NavigationSystem"
            });
    }
}
