// From LI ZHENGLIN

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

/**
 * 
 */
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class IEnemyInterface;
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AAuraPlayerController();
	virtual void PlayerTick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	
private:
	
	/**
	 * Enhanced Input
	 */
	UPROPERTY(EditAnywhere,Category="A_CustomSetting|Input")//Mappingcontext
	TObjectPtr<UInputMappingContext> AuraContext;
	
	//Input Actions
	UPROPERTY(EditAnywhere,Category="A_CustomSetting|Input")
	TObjectPtr<UInputAction> MoveAction;
	
	//Input Action Functions
	void Move(const FInputActionValue &value);//移动

	/**
	 * 功能函数 
	 */
	void CursorTrace();//获取鼠标下物体

	/**
	 *	Attributes
	 */
	TScriptInterface<IEnemyInterface> LastActor;
	TScriptInterface<IEnemyInterface> ThisActor;
	
	//TObjectPtr<IEnemyInterface>  LastActor; __old
	//TObjectPtr<IEnemyInterface>  ThisActor; __old
	
};
