// From LI ZHENGLIN

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "AuraPlayerState.generated.h"

/**
 * 
 */
class UAbilitySystemComponent;
class UAttributeSet;
UCLASS()
class AURA_API AAuraPlayerState : public APlayerState,public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	AAuraPlayerState();

protected:
	//Components
	UPROPERTY()	
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	//OtherClass
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

public:
	//Getter Setter
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	FORCEINLINE UAbilitySystemComponent * GetAbilityComponent()const{return AbilitySystemComponent;} ;
	FORCEINLINE UAttributeSet * GetAttributeSet()const{return AttributeSet;} ;
};
