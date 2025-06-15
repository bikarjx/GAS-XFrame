// Copyrights, Bikarjx 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "XFCharacterBase.generated.h"

UCLASS(Abstract)
class XFRAME_API AXFCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AXFCharacterBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
	
};
