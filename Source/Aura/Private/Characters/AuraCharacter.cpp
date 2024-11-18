// From LI ZHENGLIN


#include "Characters/AuraCharacter.h"

#include "AbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "player/AuraPlayerState.h"
#include "UI/HUD/AuraHUD.h"

AAuraCharacter::AAuraCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationPitch=false;
	bUseControllerRotationYaw=false;
	bUseControllerRotationRoll=false;

	
	
	SpringArmComponent=CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm Component"));
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->bUsePawnControlRotation=true;
	
	CameraComponent=CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);
	CameraComponent->bUsePawnControlRotation=false;

	GetCharacterMovement()->bOrientRotationToMovement=true;
	GetCharacterMovement()->RotationRate=FRotator(0.0f,460,0.f);
	GetCharacterMovement()->bConstrainToPlane=true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
}
void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitAbilitysystemsAndAttibuteSet();
	InitHUDPlayerController();
	
	
	
}
void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	InitAbilitysystemsAndAttibuteSet();
	InitHUDPlayerController();
}
void AAuraCharacter::InitHUDPlayerController()
{
	APlayerController * PlayerController=Cast<APlayerController>(GetController());
	if (!PlayerController) return;
	AAuraHUD * AuraHUD=Cast<AAuraHUD>( PlayerController->GetHUD());
	if(!AuraHUD)return;
	AAuraPlayerState* AuraPlayerState=CastChecked<AAuraPlayerState>(GetPlayerState());
	AuraHUD->InitOverlay(PlayerController,AuraPlayerState,AbilitySystemComponent,AttributeSet);
}
void AAuraCharacter::InitAbilitysystemsAndAttibuteSet()
{
	AAuraPlayerState *AuraPlayerState=Cast<AAuraPlayerState>(GetPlayerState());
	
	if(!AuraPlayerState)return;
	AbilitySystemComponent=AuraPlayerState->GetAbilitySystemComponent();
	AbilitySystemComponent->InitAbilityActorInfo(AuraPlayerState,this);
	AttributeSet=AuraPlayerState->GetAttributeSet();
}
