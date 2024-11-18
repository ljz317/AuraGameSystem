// From LI ZHENGLIN

#pragma once

#include "CoreMinimal.h"
#include "UI/Controller/AuraWidgetController.h"
#include "OverlayWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHeathChangedSignature,float,NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHeathChangedSignature,float,NewMaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManaChangedSignature,float,NewMana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxManaChangedSignature,float,NewMaxMana);
/**
 *  
 */
UCLASS(Blueprintable,Blueprintable)
class AURA_API UOverlayWidgetController : public UAuraWidgetController
 {
	GENERATED_BODY()
public:
	virtual void BroadcastInitialValues()override;
	virtual void BindCallbacksToDependencies()override;
	
	UPROPERTY(BlueprintAssignable,Category="A_CustomSetting|GAS|Attributes")
	FOnHeathChangedSignature OnHealthChanged;
	UPROPERTY(BlueprintAssignable,Category="A_CustomSetting|GAS|Attributes")
	FOnMaxHeathChangedSignature OnMaxHealthChanged;

	UPROPERTY(BlueprintAssignable,Category="A_CustomSetting|GAS|Attributes")
	FOnManaChangedSignature OnManaChanged;
	UPROPERTY(BlueprintAssignable,Category="A_CustomSetting|GAS|Attributes")
	FOnMaxManaChangedSignature OnMaxManaChanged;
	

protected:
	void HealthChanged(const FOnAttributeChangeData &Data) const;
	void MaxHealthChanged(const FOnAttributeChangeData &Data) const;
	void ManaChanged(const FOnAttributeChangeData &Data) const;
	void MaxManaChanged(const FOnAttributeChangeData &Data) const;
};
