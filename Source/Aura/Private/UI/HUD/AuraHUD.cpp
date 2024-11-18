// From LI ZHENGLIN


#include "UI/HUD/AuraHUD.h"
#include "UI/Widget/AuraUserWidget.h"
#include "UI/Controller/OverlayWidgetController.h"
#include "Blueprint/UserWidget.h"


UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if(!OverlayWidgetController)
	{
		OverlayWidgetController=NewObject<UOverlayWidgetController>(this,OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		OverlayWidgetController->BindCallbacksToDependencies();
		return OverlayWidgetController;
	}
	return OverlayWidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet *AS)
{
	checkf(OverlayWidgetControllerClass,TEXT("OverlayWidgetControllerClass is NULL ->>BP_AuraHUD::InitOverlay"));
	checkf(OverlayWidgetClass,TEXT("OverlayWidgetClass is NULL ->>BP_AuraHUD::InitOverlay"));
	
	
	if (UUserWidget * UserWidget= CreateWidget(GetWorld(),OverlayWidgetClass))
	{
		OverlayWidget=Cast<UAuraUserWidget>(UserWidget);
		const FWidgetControllerParams WidgetControllerParams(PC,PS,ASC,AS);
		UOverlayWidgetController *WidgetController= GetOverlayWidgetController(WidgetControllerParams);
		
		OverlayWidget->SetWidgetController(WidgetController);
		WidgetController->BroadcastInitialValues();

		
		OverlayWidget->AddToViewport();
	}
	
}
