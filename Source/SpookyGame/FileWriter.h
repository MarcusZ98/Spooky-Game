// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FileWriter.generated.h"

/**
 * 
 */
UCLASS()
class SPOOKYGAME_API UFileWriter : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static bool WriteToFile(FString SaveText, FString FileName);
	
};
