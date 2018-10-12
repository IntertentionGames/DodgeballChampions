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


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
    
    PhisicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
    if(PhisicsHandle){
        
        
        
        
    }
    
    InputComponents = GetOwner()->FindComponentByClass<UInputComponent>();
    if  (InputComponents){
        
        InputComponents->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
        InputComponents->BindAction("Release", IE_Released, this, &UGrabber::Released);
}
    
}


void UGrabber::Grab(){
    //Could be refactored
    FVector PlayerViewPointLocation;
    FRotator PlayerViewPointRotation;
    
    GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayerViewPointLocation, PlayerViewPointRotation);
    
    FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector()*Reach;
    
    
    
    FHitResult LineTraceHit;
    
    FCollisionQueryParams TracePeram (FName(TEXT("")),false,GetOwner());
    
    GetWorld()->LineTraceSingleByObjectType(LineTraceHit, PlayerViewPointLocation, LineTraceEnd, FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),TracePeram);
    
    AActor* ActorHit = LineTraceHit .GetActor();
    if (ActorHit){
    }
    
    PhisicsHandle->GrabComponentAtLocation(, NAME_None, PlayerViewPointLocation);
    

void UGrabber::Released(){
     UE_LOG(LogTemp, Warning, TEXT("Released"));
    
}



// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}


