// Copyright 2020-2030 AlemdarLabs, All Rights Reserved

#include "DebugUtilitiesSettings.h"

UDebugUtilitiesSettings::UDebugUtilitiesSettings(const FObjectInitializer& ObjectInitializer)
{
	bEnableSpecifiers = false;
	
	LogCategorySpecifiers.Empty();
	LogCategorySpecifiers.Add(DL_Info, "[Info]: ");
	LogCategorySpecifiers.Add(DL_Warning, "[Warning]: ");
	LogCategorySpecifiers.Add(DL_Success, "[Success]: ");
	LogCategorySpecifiers.Add(DL_Error, "[Error]: ");
	LogCategorySpecifiers.Add(DL_Fatal, "[Fatal]: ");
}
