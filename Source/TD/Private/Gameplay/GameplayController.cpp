// Fill out your copyright notice in the Description page of Project Settings.
#include "GameplayController.h"
#include "GameFramework/Pawn.h"
#include "WidgetLayoutLibrary.h"

void AGameplayController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	CheckEdgeScroll();
}

void AGameplayController::CheckEdgeScroll()
{
	FVector2D t_MousePos;
	FVector2D t_ViewportSize = UWidgetLayoutLibrary::GetViewportSize(GetWorld());
	APawn* t_Pawn = GetPawn();
	if (GetMousePosition(t_MousePos.X, t_MousePos.Y))
	{
		if (t_MousePos.X / t_ViewportSize.X < 0.01)//左滚动
		{
			t_Pawn->AddMovementInput(FRotationMatrix(GetControlRotation()).GetScaledAxis(EAxis::Y), -1);
		}
		if (t_MousePos.X / t_ViewportSize.X > 0.99)//右滚动
		{
			t_Pawn->AddMovementInput(FRotationMatrix(GetControlRotation()).GetScaledAxis(EAxis::Y), 1);
		}
		if (t_MousePos.Y / t_ViewportSize.Y < 0.01)//上滚动
		{
			t_Pawn->AddMovementInput(GetControlRotation().Vector(), 1);
		}
		if (t_MousePos.Y / t_ViewportSize.Y > 0.99)//下滚动
		{
			t_Pawn->AddMovementInput(GetControlRotation().Vector(), -1);
		}
	}
	else //鼠标在最左上角边缘时,Line17的GetMousePosition无效
	{
		t_MousePos = UWidgetLayoutLibrary::GetMousePositionOnViewport(GetWorld());
		if (t_MousePos.X / t_ViewportSize.X < 0.01)//左滚动
		{
			t_Pawn->AddMovementInput(FRotationMatrix(GetControlRotation()).GetScaledAxis(EAxis::Y), -1);
		}
		if (t_MousePos.Y / t_ViewportSize.Y < 0.01)//上滚动
		{
			t_Pawn->AddMovementInput(GetControlRotation().Vector(), 1);
		}
	}
}
