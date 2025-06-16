// Copyrights, Bikarjx 2025. All Rights Reserved.


#include "Character/XFEnemy.h"
#include "AbilitySystem/XFAbilitySystemComponent.h"
#include "AbilitySystem/XFAttributeSet.h"
#include "XFrame/XFrame.h"


AXFEnemy::AXFEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility,ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UXFAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);


	AttributeSet = CreateDefaultSubobject<UXFAttributeSet>("AttributeSet");
}

void AXFEnemy::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	
}

void AXFEnemy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
	
}

void AXFEnemy::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
