// Copyrights, Bikarjx 2025. All Rights Reserved.


#include "Player/XFPlayerState.h"
#include "AbilitySystem/XFAbilitySystemComponent.h"
#include "AbilitySystem/XFAttributeSet.h"

AXFPlayerState::AXFPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UXFAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<UXFAttributeSet>("AttributeSet");
	
	SetNetUpdateFrequency(100.f);
}

UAbilitySystemComponent* AXFPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
