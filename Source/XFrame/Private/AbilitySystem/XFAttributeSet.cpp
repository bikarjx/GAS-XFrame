// Copyrights, Bikarjx 2025. All Rights Reserved.


#include "AbilitySystem/XFAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"


UXFAttributeSet::UXFAttributeSet()
{
	InitHealth(75.f);
	InitMaxHealth(100.f);
	InitMana(45.f);
	InitMaxMana(60.f);
}

void UXFAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UXFAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXFAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXFAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UXFAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

void UXFAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXFAttributeSet, Health, OldHealth);
}

void UXFAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXFAttributeSet, MaxHealth, OldMaxHealth);
}

void UXFAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXFAttributeSet, Mana, OldMana);
}

void UXFAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UXFAttributeSet, MaxMana, OldMaxMana);
}
