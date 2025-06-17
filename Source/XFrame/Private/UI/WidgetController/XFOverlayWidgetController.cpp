// Copyrights, Bikarjx 2025. All Rights Reserved.


#include "UI/WidgetController/XFOverlayWidgetController.h"
#include "AbilitySystem/XFAttributeSet.h"


void UXFOverlayWidgetController::BroadcastInitialValues()
{
	Super::BroadcastInitialValues();

	const UXFAttributeSet* XFAttributeSet = CastChecked<UXFAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(XFAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(XFAttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(XFAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(XFAttributeSet->GetMaxMana());
}

void UXFOverlayWidgetController::BindCallbacksToDependencies()
{
	Super::BindCallbacksToDependencies();
	
	const UXFAttributeSet* XFAttributeSet = CastChecked<UXFAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(XFAttributeSet->GetHealthAttribute()).AddUObject
		(this, &UXFOverlayWidgetController::HealthChanged );
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(XFAttributeSet->GetMaxHealthAttribute()).AddUObject
		(this, &UXFOverlayWidgetController::MaxHealthChanged );
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(XFAttributeSet->GetManaAttribute()).AddUObject
		(this, &UXFOverlayWidgetController::ManaChanged );
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(XFAttributeSet->GetMaxManaAttribute()).AddUObject
		(this, &UXFOverlayWidgetController::MaxManaChanged );
	

	
}

void UXFOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UXFOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UXFOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UXFOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
