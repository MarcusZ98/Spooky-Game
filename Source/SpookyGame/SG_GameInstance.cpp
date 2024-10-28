// Fill out your copyright notice in the Description page of Project Settings.


#include "SG_GameInstance.h"

void USG_GameInstance::Init()
{
	Super::Init();
	ReadIniFile();
	SetLogPath();
}

void USG_GameInstance::ReadIniFile()
{

	const FString Path = FPlatformProperties::RequiresCookedData() ?
		FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("Config/Windows/CustomConfig.ini")) :
		FPaths::ProjectConfigDir() + "CustomConfig.ini";
	
	if(GConfig)
	{
		//Enemy
		GConfig->GetFloat(TEXT("Enemy"), TEXT("EnemyHealth"), EnemyHealth, Path);


		//Controller
		GConfig->GetFloat(TEXT("Controller"), TEXT("LookSpeedMultiplier"), LookSpeedMultiplier, Path);
		GConfig->GetFloat(TEXT("Controller"), TEXT("WalkSpeedMultiplier"), WalkSpeedMultiplier, Path);
	}


	
}

void USG_GameInstance::SetLogPath()
{
	LogFilePath = FPlatformProperties::RequiresCookedData() ?
		FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("Logs/CustomLog.txt")) :
		FPaths::ProjectLogDir() + "SpookyGame.txt";
		
}
