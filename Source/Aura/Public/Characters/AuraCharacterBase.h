// From LI ZHENGLIN

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "AuraCharacterBase.generated.h"
class UAbilitySystemComponent;
class UAttributeSet;
UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter,public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AAuraCharacterBase();

protected:
	virtual void BeginPlay() override;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const  override;
	
	//Components
	UPROPERTY(EditAnywhere,Category="A_CustomSetting|Component")
	TObjectPtr<USkeletalMeshComponent> Weapon;
	UPROPERTY()	
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	//Getter Setter
	FORCEINLINE UAbilitySystemComponent * GetAbilityComponent()const{return AbilitySystemComponent;} ;
};
