// From LI ZHENGLIN

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "MYTEST_AuraEnhanced_01.generated.h"

/**
 * 
 */

class UInputMappingContext;
struct FInputActionValue;
class UInputAction;
UCLASS()
class AURA_API AMYTEST_AuraEnhanced_01 : public APlayerController
{
	GENERATED_BODY()

public:
	AMYTEST_AuraEnhanced_01();
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputMappingContext> InputMappingContext;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputAction> MoveAction;
	
	void Move(const FInputActionValue &Value);
};
