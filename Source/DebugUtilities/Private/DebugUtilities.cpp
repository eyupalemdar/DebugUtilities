// Copyright Epic Games, Inc. All Rights Reserved.

#include "DebugUtilities.h"
#include "DebugUtilitiesSettings.h"
#include "LogUtilities.h"

#if WITH_EDITOR
#include "ISettingsModule.h"
#endif

#define LOCTEXT_NAMESPACE "FDebugUtilitiesModule"

void FDebugUtilitiesModule::StartupModule()
{
	RegisterSettings();
}

void FDebugUtilitiesModule::ShutdownModule()
{
	if (UObjectInitialized())
	{
		UnRegisterSettings();
	}
}

bool FDebugUtilitiesModule::SupportsDynamicReloading()
{
	return true;
}

bool FDebugUtilitiesModule::HandleSettingsSaved()
{
#if WITH_EDITOR
	UDebugUtilitiesSettings* Settings = GetMutableDefault<UDebugUtilitiesSettings>();

	Settings->SaveConfig();
#endif
	
	return true;
}

void FDebugUtilitiesModule::RegisterSettings()
{
#if WITH_EDITOR
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "Debug Utilities",
			LOCTEXT("RuntimeSettingsName", "Debug Utilities"),
			LOCTEXT("RuntimeSettingsDescription", "Configure the Debug Utilities plugin"),
			GetMutableDefault<UDebugUtilitiesSettings>());
	}
#endif
}

void FDebugUtilitiesModule::UnRegisterSettings()
{
#if WITH_EDITOR
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "Debug Utilities");
	}
#endif
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FDebugUtilitiesModule, DebugUtilities)

DEFINE_LOG_CATEGORY(LogSuccess)
DEFINE_LOG_CATEGORY(LogError)
DEFINE_LOG_CATEGORY(LogFatal)
DEFINE_LOG_CATEGORY(LogCrash)
DEFINE_LOG_CATEGORY(LogWarning)
DEFINE_LOG_CATEGORY(LogNumber)
DEFINE_LOG_CATEGORY(LogUnit)
DEFINE_LOG_CATEGORY(LogFColor)
DEFINE_LOG_CATEGORY(LogCapsule)
DEFINE_LOG_CATEGORY(LogBox)
DEFINE_LOG_CATEGORY(LogSphere)
DEFINE_LOG_CATEGORY(LogBool)
DEFINE_LOG_CATEGORY(LogVector)
DEFINE_LOG_CATEGORY(LogRotator)
DEFINE_LOG_CATEGORY(LogTransform)
DEFINE_LOG_CATEGORY(LogQuaternion)
DEFINE_LOG_CATEGORY(LogMatrix)
DEFINE_LOG_CATEGORY(LogDateTime)
DEFINE_LOG_CATEGORY(LogEnum)
DEFINE_LOG_CATEGORY(LogArray)
DEFINE_LOG_CATEGORY(LogMessage)
DEFINE_LOG_CATEGORY(LogLineBreak)
DEFINE_LOG_CATEGORY(LogObjectValidity)