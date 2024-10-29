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

		//Dialogue
		GConfig->GetFloat(TEXT("Dialogue"), TEXT("DialogueDelay"), DialogueDelay, Path);
	}


	
}

void USG_GameInstance::SetLogPath()
{
	LogFilePath = FPlatformProperties::RequiresCookedData() ?
		FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("Logs/CustomLog.txt")) :
		FPaths::ProjectConfigDir() + "CustomLog.txt";
		
}


bool USG_GameInstance::WriteToFile(FString LogString)
{
	USG_GameInstance* GI = Cast<USG_GameInstance>(GetWorld()->GetGameInstance());
	FString Path = GI->LogFilePath;

	// Get the current date and time
	FString Timestamp = FDateTime::Now().ToString(TEXT("[%Y-%m-%d %H:%M:%S] "));

	//Get level Name
	FString LevelName = GetWorld()->GetMapName();
	LevelName.RemoveFromStart(GetWorld()->StreamingLevelsPrefix);

	// Prepend timestamp to the log string
	LogString = FString::Printf(TEXT("%s [Level: %s] %s"), *Timestamp, *LevelName, *LogString);

	// Check if we need to add a newline to the log
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	if (PlatformFile.FileExists(*Path))
	{
		LogString = "\n" + LogString; // Add newline if file exists
	}

	// Write to the file in append mode
	if (!FFileHelper::SaveStringToFile(LogString, *Path, FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(), FILEWRITE_Append))
	{
		return false;
	}

	return true;
}