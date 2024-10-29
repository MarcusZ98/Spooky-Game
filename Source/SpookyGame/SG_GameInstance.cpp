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
	
	if(!FFileHelper::SaveStringToFile(LogString, *Path))
	{
		return false;
	}

	return true;
}