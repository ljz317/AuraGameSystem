// From LI ZHENGLIN

#pragma once

#include "CoreMinimal.h"
#include "Characters/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

/**
 * 
 */
class USpringArmComponent;
class UCameraComponent;
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	AAuraCharacter();
	
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

protected:
	
private:
	//Components
	UPROPERTY(EditAnywhere)
	TObjectPtr<USpringArmComponent> SpringArmComponent;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UCameraComponent> CameraComponent;

	//初始化
	void InitAbilitysystemsAndAttibuteSet();
};