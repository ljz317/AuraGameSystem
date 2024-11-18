// From LI ZHENGLIN


#include "Player/AuraPlayerController.h"
//EnhancedInput
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"


AAuraPlayerController::AAuraPlayerController()
{
	bReplicates=true;
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);
	UEnhancedInputLocalPlayerSubsystem *subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if(!subsystem)return;
	subsystem->AddMappingContext(AuraContext,0);

	bShowMouseCursor=true;
	DefaultMouseCursor=EMouseCursor::Default;

	FInputModeGameAndUI InputModeDate ;
	InputModeDate.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeDate.SetHideCursorDuringCapture(false);

	SetInputMode(InputModeDate);
	
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent * EnhancedInputComponent=CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this,&ThisClass::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& value)
{
	const FVector2d InputAxisVector=value.Get<FVector2d>();
	const FRotator Rotation= GetControlRotation();
	const FRotator YawRotation=FRotator(0,Rotation.Yaw,0);
	const FVector ForwardDirection=FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection=FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if(APawn *ControlledPawn=GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection,InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection,InputAxisVector.X);
	}
}

void AAuraPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility,false,CursorHit);
	if(!CursorHit.bBlockingHit) return;

	LastActor=ThisActor;
	ThisActor=CursorHit.GetActor();
	if(LastActor.GetInterface()==nullptr)
	{
		if(ThisActor.GetInterface()!=nullptr)ThisActor->HighlightActor(); // l=n,t!=n 高亮this
	}
	else
	{
		if(ThisActor.GetInterface()==nullptr)
		{
			LastActor.GetInterface()->UnHighlightActor();// l！=n,t=n 取消高亮last
		}
		else
		{
			if(LastActor.GetInterface()!=ThisActor.GetInterface())// l！=n,t!=n,l!=t 取消高亮last,高亮this
			{
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}
		}
	}
}
