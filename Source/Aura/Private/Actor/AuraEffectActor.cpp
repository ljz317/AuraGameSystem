// From LI ZHENGLIN


#include "Actor/AuraEffectActor.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AttributeSet.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Components/SphereComponent.h"

AAuraEffectActor::AAuraEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;
	
	StaticMeshComp=CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	SetRootComponent(StaticMeshComp);
	
	SphereComp=CreateDefaultSubobject<USphereComponent>("SphereComponent");
	SphereComp->SetupAttachment(GetRootComponent());

	
	
}

void AAuraEffectActor::OnOverlap( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if(IAbilitySystemInterface * AbilitySystemInterface=Cast<IAbilitySystemInterface>(OtherActor))
	{
		UAbilitySystemComponent *AbilityComp= AbilitySystemInterface->GetAbilitySystemComponent();
		const UAuraAttributeSet *AttributeSet=Cast<UAuraAttributeSet>(AbilityComp->GetAttributeSet(UAuraAttributeSet::StaticClass()));
		if(AttributeSet)
		{
			UAuraAttributeSet * noconst=const_cast<UAuraAttributeSet * >(AttributeSet);
			noconst->SetHealth(noconst->GetHealth()+HealthBuffEffect);
			noconst->SetMana(noconst->GetMana()+ManaBuffEffect); 
			Destroy();
		}
	}
	
}

void AAuraEffectActor::EndOverlap( UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
	SphereComp->OnComponentBeginOverlap.AddDynamic(this,&ThisClass::OnOverlap);
	SphereComp->OnComponentEndOverlap.AddDynamic(this,&ThisClass::EndOverlap);
}
