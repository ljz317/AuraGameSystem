// From LI ZHENGLIN


#include "UI/Controller/AuraWidgetController.h"

#include "AbilitySystem/AuraAttributeSet.h"

void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController=WCParams.PlayerController;
	PlayerState=WCParams.PlayerState;
	AbilitySystemComponent=WCParams.AbilitySystemComponent;
	AttributeSet=WCParams.AttributeSet;
}

void UAuraWidgetController::BroadcastInitialValues()
{
	
	
}

void UAuraWidgetController::BindCallbacksToDependencies()
{
}


