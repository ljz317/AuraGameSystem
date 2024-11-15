// From LI ZHENGLIN


#include "Test/Enhanced/MYTEST_AuraEnhanced_01.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"

AMYTEST_AuraEnhanced_01::AMYTEST_AuraEnhanced_01()
{
	bReplicates=true;
}

void AMYTEST_AuraEnhanced_01::BeginPlay()
{
	Super::BeginPlay();
	check(InputMappingContext);
	check(MoveAction);
	UEnhancedInputLocalPlayerSubsystem * system=ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	system->AddMappingContext(InputMappingContext,0);

	bShowMouseCursor=true;
	DefaultMouseCursor=EMouseCursor::Default;

	FInputModeGameAndUI InputMode;
	InputMode.SetHideCursorDuringCapture(false);
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockInFullscreen);
	
	SetInputMode(InputMode);
}

void AMYTEST_AuraEnhanced_01::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent *InputCompo=CastChecked<UEnhancedInputComponent>(InputComponent);
	InputCompo->BindAction(MoveAction,ETriggerEvent::Triggered,this,&ThisClass::Move);
}

void AMYTEST_AuraEnhanced_01::Move (const FInputActionValue & Value)
{
	const FVector2d vector2d=Value.Get<FVector2d>();
	const FRotator Rotation=GetControlRotation();
	const FRotator YawRotation=FRotator(0.0f,Rotation.Yaw,0.0f);
	const FVector Forward=FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector Right=FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if(APawn * pawn=GetPawn<APawn>())
	{
		pawn->AddMovementInput(Forward,vector2d.Y);
		pawn->AddMovementInput(Right,vector2d.X);
	}
}
