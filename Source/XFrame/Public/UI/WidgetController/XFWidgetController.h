// Copyrights, Bikarjx 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "XFWidgetController.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;


USTRUCT(BlueprintType)
struct FWidgetControllerParams
{
	GENERATED_BODY()

	FWidgetControllerParams() {}
	FWidgetControllerParams(APlayerController* PC,APlayerState* PS,UAbilitySystemComponent* ASC,UAttributeSet* AS)
	: PlayerController(PC),PlayerState(PS),AbilitySystemComponent(ASC),AttributeSet(AS) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "XFrame WidgetController")
	TObjectPtr<APlayerController> PlayerController = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "XFrame WidgetController")
	TObjectPtr<APlayerState> PlayerState = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "XFrame WidgetController")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "XFrame WidgetController")
	TObjectPtr<UAttributeSet> AttributeSet = nullptr;
	
	
};
/**
 * 
 */
UCLASS()
class XFRAME_API UXFWidgetController : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "XFrame WidgetController")
	void SetWidgetControllerParams(const FWidgetControllerParams& WCParams);

protected:

	UPROPERTY(BlueprintReadOnly, Category = "XFrame WidgetController")
	TObjectPtr<APlayerController> PlayerController;
	
	UPROPERTY(BlueprintReadOnly, Category = "XFrame WidgetController")
	TObjectPtr<APlayerState> PlayerState;
	
	UPROPERTY(BlueprintReadOnly, Category = "XFrame WidgetController")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY(BlueprintReadOnly, Category= "XFrame WidgetController")
	TObjectPtr<UAttributeSet> AttributeSet;
	
};
