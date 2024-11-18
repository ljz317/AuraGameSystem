// From LI ZHENGLIN


#include "UI/Widget/AuraUserWidget.h"

void UAuraUserWidget::SetWidgetController(UObject* InWidgetConTroller)
{
	WidgetController=InWidgetConTroller;
	WidgetControllerSet();
}
