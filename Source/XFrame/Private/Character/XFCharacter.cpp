// Copyrights, Bikarjx 2025. All Rights Reserved.


#include "Character/XFCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

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
