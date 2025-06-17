// Copyrights, Bikarjx 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "XFHUD.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
class UXFOverlayWidgetController;
class UXFWidgetController;
class UXFUserWidget;
struct FWidgetControllerParams;
/**
 * 
 */
UCLASS()
class XFRAME_API AXFHUD : public AHUD
{
	GENERATED_BODY()

public:

	UPROPERTY()
	TObjectPtr<UXFUserWidget> OverlayWidget;

	UXFOverlayWidgetController* GetXFOverlayWidgetController(const FWidgetControllerParams& WCParams);

	void InitOverlay(APlayerController* PC,APlayerState* PS,UAbilitySystemComponent* ASC, UAttributeSet* AS);

protected:

	
private:

	UPROPERTY(EditAnywhere, Category = "XFrame HUD")
	TSubclassOf<UXFUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UXFOverlayWidgetController> OverlayWidgetController;
	
	UPROPERTY(EditAnywhere, Category = "XFrame HUD")
	TSubclassOf<UXFOverlayWidgetController> OverlayWidgetControllerClass;
};
