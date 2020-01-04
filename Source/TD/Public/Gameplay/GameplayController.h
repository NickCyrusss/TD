// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameplayController.generated.h"

/**
 * 
 */
UCLASS()
class TD_API AGameplayController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void Tick(float DeltaSeconds);

private:
	//检查边缘滚动
	void CheckEdgeScroll();
	
};
