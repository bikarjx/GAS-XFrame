// Copyrights, Bikarjx 2025. All Rights Reserved.


#include "Actor/XFEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/XFAttributeSet.h"
#include "Components/SphereComponent.h"


AXFEffectActor::AXFEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());

	
}

void AXFEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//~ TODO: Change this to apply a gameplay effect. for now, using const_cast as a hack?! ~/ 
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UXFAttributeSet* XFAttributeSet = Cast<UXFAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UXFAttributeSet::StaticClass()));
		
		UXFAttributeSet* MutableXFAttributeSet = const_cast<UXFAttributeSet*>(XFAttributeSet);
		MutableXFAttributeSet->SetHealth(XFAttributeSet->GetHealth() + 10.f);

		Destroy();
	}
}

void AXFEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

void AXFEffectActor::BeginPlay()
{
	Super::BeginPlay();

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AXFEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AXFEffectActor::EndOverlap);
}

