// Copyrights, Bikarjx 2025. All Rights Reserved.


#include "UI/WidgetController/XFWidgetController.h"

void UXFWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UXFWidgetController::BroadcastInitialValues()
{
	
}

void UXFWidgetController::BindCallbacksToDependencies()
{
	
}
