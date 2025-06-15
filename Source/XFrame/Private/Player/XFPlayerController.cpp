// Copyrights, Bikarjx 2025. All Rights Reserved.


#include "Player/XFPlayerController.h"

#include "EnhancedInputSubsystems.h"

AXFPlayerController::AXFPlayerController()
{
	bReplicates = true;
}

void AXFPlayerController::BeginPlay()
{
	
	Super::BeginPlay();
	check(XFrameContext);
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(XFrameContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
		
}
