// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

//NO IMPUT COMPONENT IN THE GAME YET I THINK
// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
    
    PhisicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
    if(PhisicsHandle){
        
    }
    
    //InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
    //if  (InputComponent){
        
    //}
    
    
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    
    
     FVector PlayerViewPointLocation;
     FRotator PlayerViewPointRotation;
    
    GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayerViewPointLocation, PlayerViewPointRotation);
    
    FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector()*Reach;
    
    
    
    FHitResult LineTraceHit;
    
    FCollisionQueryParams TracePeram (FName(TEXT("")),false,GetOwner());
    
    GetWorld()->LineTraceSingleByObjectType(LineTraceHit, PlayerViewPointLocation, LineTraceEnd, FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),TracePeram);
    
    AActor* ActorHit = LineTraceHit .GetActor();
    if (ActorHit){
        UE_LOG(LogTemp,Warning,TEXT("%s"),*(ActorHit->GetName()))
    }
}
