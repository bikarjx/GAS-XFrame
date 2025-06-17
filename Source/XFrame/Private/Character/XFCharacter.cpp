// Copyrights, Bikarjx 2025. All Rights Reserved.


#include "Character/XFCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/XFPlayerController.h"
#include "Player/XFPlayerState.h"
#include "UI/HUD/XFHUD.h"

AXFCharacter::AXFCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

void AXFCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	//~ Init Ability actor info on the server
	InitAbilityActorInfo();
}

void AXFCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	//~ Init Ability actor info on the client
	InitAbilityActorInfo();
}

void AXFCharacter::InitAbilityActorInfo()
{
	AXFPlayerState* XFPlayerState = GetPlayerState<AXFPlayerState>();
	check(XFPlayerState);
	XFPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(XFPlayerState, this);
	AbilitySystemComponent = XFPlayerState->GetAbilitySystemComponent();
	AttributeSet = XFPlayerState->GetAttributeSet();

	if (AXFPlayerController* XFPlayerController = Cast<AXFPlayerController>(GetController()))
	{
		if (AXFHUD* XFHUD = Cast<AXFHUD>(XFPlayerController->GetHUD()))
		{
			XFHUD->InitOverlay(XFPlayerController, XFPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
	
}
