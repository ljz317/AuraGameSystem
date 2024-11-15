// From LI ZHENGLIN


#include "Characters/AuraCharacterBase.h"

AAuraCharacterBase::AAuraCharacterBase()
{
	Weapon=CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(),"WeaponHandSocket");
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	PrimaryActorTick.bCanEverTick = true;

}

void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

UAbilitySystemComponent* AAuraCharacterBase::GetAbilitySystemComponent() const
{
	
	return AbilitySystemComponent;
}


