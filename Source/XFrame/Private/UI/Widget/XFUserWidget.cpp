// Copyrights, Bikarjx 2025. All Rights Reserved.


#include "UI/Widget/XFUserWidget.h"

void UXFUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
