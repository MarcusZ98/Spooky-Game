// Fill out your copyright notice in the Description page of Project Settings.


#include "SG_GameInstance.h"

void USG_GameInstance::Init()
{
	Super::Init();
	ReadIniFile();
}

void USG_GameInstance::ReadIniFile()
{
	// for Editor
	FString Path = FPaths::ProjectConfigDir() + "CustomConfig.ini";

	// for Packaged Game
	//FString Path = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("Config/Windows/CustomConfig.ini"));

	if(GConfig)
	{
		//Audio
		GConfig->GetFloat(TEXT("Audio"), TEXT("UIVolumeMultiplier"), MasterVolumeMultiplier, Path);
		GConfig->GetFloat(TEXT("Audio"), TEXT("MusicVolumeMultiplier"), MusicVolumeMultiplier, Path);
		GConfig->GetFloat(TEXT("Audio"), TEXT("SFXVolumeMultiplier"), SFXVolumeMultiplier, Path);
		GConfig->GetFloat(TEXT("Audio"), TEXT("VoiceVolumeMultiplier"), VoiceVolumeMultiplier, Path);

		//Controller
		GConfig->GetFloat(TEXT("Controller"), TEXT("LookSpeedMultiplier"), LookSpeedMultiplier, Path);
		GConfig->GetFloat(TEXT("Controller"), TEXT("WalkSpeedMultiplier"), WalkSpeedMultiplier, Path);
	}
}
