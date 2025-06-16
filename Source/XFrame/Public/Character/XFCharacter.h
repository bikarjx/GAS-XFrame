// Copyrights, Bikarjx 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/XFCharacterBase.h"
#include "XFCharacter.generated.h"

/**
 * 
 */
UCLASS()
class XFRAME_API AXFCharacter : public AXFCharacterBase
{
	GENERATED_BODY()

public:
	AXFCharacter();
	
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:
	void InitAbilityActorInfo();
};
