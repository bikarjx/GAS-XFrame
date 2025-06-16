// Copyrights, Bikarjx 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/XFCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "XFEnemy.generated.h"

/**
 * 
 */
UCLASS()
class XFRAME_API AXFEnemy : public AXFCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AXFEnemy();
	
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	
};
