// From LI ZHENGLIN

#pragma once

#include "CoreMinimal.h"
#include "Characters/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase,public IEnemyInterface
{
	GENERATED_BODY()
public:
	AAuraEnemy();
	virtual void BeginPlay() override;
    virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

	
protected:
	//UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="A_CustomSetting|Attributes")
private:
	
};
