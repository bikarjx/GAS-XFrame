// Copyrights, Bikarjx 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "XFPlayerController.generated.h"

class UInputMappingContext;
/**
 * 
 */
UCLASS()
class XFRAME_API AXFPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AXFPlayerController();

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> XFrameContext;
	
};
