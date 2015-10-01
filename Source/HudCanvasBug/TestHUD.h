// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "TestHUD.generated.h"

/**
 * Test HUD class.
 */
UCLASS()
class HUDCANVASBUG_API ATestHUD : public AHUD
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Draw Buggy Text", Keywords = "buggy text"), Category = "HUD")
	void DrawBuggyText(const FString& Text, FVector2D Position, UFont* TextFont){
		float XL, YL;

		Canvas->TextSize(TextFont, Text, XL, YL);
		const float X = Canvas->ClipX / 2.0f - XL / 2.0f + Position.X;
		const float Y = Canvas->ClipY / 2.0f - YL / 2.0f + Position.Y;

		FCanvasTextItem TextItem(FVector2D(X, Y), FText::FromString(Text), TextFont, FLinearColor::White);
		TextItem.bOutlined = true;
		TextItem.OutlineColor = FLinearColor::Red;
		TextItem.EnableShadow(FLinearColor::Black, FVector2D{ 2, 2 });

		Canvas->DrawItem(TextItem);
	}
	
};
