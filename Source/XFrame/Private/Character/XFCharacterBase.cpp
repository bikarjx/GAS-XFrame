// Copyrights, Bikarjx 2025. All Rights Reserved.


#include "Character/XFCharacterBase.h"

AXFCharacterBase::AXFCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(),FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AXFCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


void AXFCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

