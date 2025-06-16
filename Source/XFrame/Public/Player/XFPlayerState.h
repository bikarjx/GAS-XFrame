// Copyrights, Bikarjx 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "XFPlayerState.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class XFRAME_API AXFPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	
	AXFPlayerState();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const {return AttributeSet;}

protected:

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
	
};
