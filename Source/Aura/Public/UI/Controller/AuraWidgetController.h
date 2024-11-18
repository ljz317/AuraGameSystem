// From LI ZHENGLIN

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "UObject/NoExportTypes.h"
#include "AuraWidgetController.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;


USTRUCT(BlueprintType)
struct FWidgetControllerParams
{
	GENERATED_BODY()

	FWidgetControllerParams(){};
	FWidgetControllerParams(APlayerController *PC,APlayerState * PS,UAbilitySystemComponent *ASC,UAttributeSet *AS)
	:PlayerController(PC),PlayerState(PS),AbilitySystemComponent(ASC),AttributeSet(AS)
	{};
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="A_CustomSetting|WidgetController")
	TObjectPtr<APlayerController> PlayerController=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="A_CustomSetting|WidgetController")
	TObjectPtr<APlayerState> PlayerState=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="A_CustomSetting|WidgetController")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent=nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="A_CustomSetting|WidgetController")
	TObjectPtr<UAttributeSet> AttributeSet=nullptr ;
};
/**
 * 
 */
UCLASS()
class AURA_API UAuraWidgetController : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetControllerParams(const FWidgetControllerParams &WCParams);

	virtual void BroadcastInitialValues();

	virtual void BindCallbacksToDependencies();
protected:
	
	
	UPROPERTY(BlueprintReadOnly, Category="A_CustomSetting|WidgetController")
	TObjectPtr<APlayerController> PlayerController;
	UPROPERTY(BlueprintReadOnly, Category="A_CustomSetting|WidgetController")
	TObjectPtr<APlayerState> PlayerState;
	UPROPERTY(BlueprintReadOnly, Category="A_CustomSetting|WidgetController")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(BlueprintReadOnly, Category="A_CustomSetting|WidgetController")
	TObjectPtr<UAttributeSet> AttributeSet;


	
};
