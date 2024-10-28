// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SG_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SPOOKYGAME_API USG_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;

	void ReadIniFile();

	void SetLogPath();
	
	UFUNCTION(BlueprintCallable, Category = "Logging")
	bool WriteToFile(FString LogString);

	FString LogFilePath;

	//////////////////////////////////////////////////////////////////////////
	//CONFIG VARIABLES
	//////////////////////////////////////////////////////////////////////////

	//Enemy
	UPROPERTY(BlueprintReadOnly, Category = "Config")
	float EnemyHealth = 3;
	

	//Controller
	UPROPERTY(BlueprintReadOnly, Category = "Config")
	float LookSpeedMultiplier = 1;
	
	UPROPERTY(BlueprintReadOnly, Category = "Config")
	float WalkSpeedMultiplier = 1;
	
};
