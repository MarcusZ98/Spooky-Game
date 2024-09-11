// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpookyGame_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_SpookyGame;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_SpookyGame()
	{
		if (!Z_Registration_Info_UPackage__Script_SpookyGame.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/SpookyGame",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xB3E15F15,
				0x7B53EA65,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_SpookyGame.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_SpookyGame.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_SpookyGame(Z_Construct_UPackage__Script_SpookyGame, TEXT("/Script/SpookyGame"), Z_Registration_Info_UPackage__Script_SpookyGame, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xB3E15F15, 0x7B53EA65));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
