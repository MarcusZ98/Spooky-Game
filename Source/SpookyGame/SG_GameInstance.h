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

	//////////////////////////////////////////////////////////////////////////
	//CONFIG VARIABLES
	//////////////////////////////////////////////////////////////////////////

	//Audio
	UPROPERTY(BlueprintReadOnly, Category = "Congig")
	float MasterVolumeMultiplier;

	UPROPERTY(BlueprintReadOnly, Category = "Congig")
	float MusicVolumeMultiplier;

	UPROPERTY(BlueprintReadOnly, Category = "Congig")
	float SFXVolumeMultiplier;

	UPROPERTY(BlueprintReadOnly, Category = "Congig")
	float VoiceVolumeMultiplier;

	//Controller
	UPROPERTY(BlueprintReadOnly, Category = "Congig")
	float LookSpeedMultiplier;
	
	UPROPERTY(BlueprintReadOnly, Category = "Congig")
	float WalkSpeedMultiplier;
	
};
