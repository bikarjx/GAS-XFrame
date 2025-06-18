// Copyrights, Bikarjx 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "XFEffectActor.generated.h"

/**
 * 
 */
class UGameplayEffect;
UCLASS()
class XFRAME_API AXFEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AXFEffectActor();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "XFrame Applied Effect")
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "XFrame Applied Effect type")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "XFrame Applied Effect type")
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;

	//~ untested yet
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "XFrame Applied Effect type")
	TSubclassOf<UGameplayEffect> InfiniteGameplayEffectClass;
	
};
