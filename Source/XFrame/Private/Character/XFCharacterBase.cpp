// Copyrights, Bikarjx 2025. All Rights Reserved.


#include "Character/XFCharacterBase.h"

// Sets default values
AXFCharacterBase::AXFCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AXFCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AXFCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AXFCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

