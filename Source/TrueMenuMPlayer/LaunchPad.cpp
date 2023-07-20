// Fill out your copyright notice in the Description page of Project Settings.


#include "LaunchPad.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Character.h"

// Sets default values
ALaunchPad::ALaunchPad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	SetRootComponent(CollisionBox);
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OverlapBegin);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	StaticMesh->SetupAttachment(RootComponent);

	DashForce = 2500.0f;
	JumpForce = 1500.0f;

}

// Called when the game starts or when spawned
void ALaunchPad::BeginPlay()
{
	Super::BeginPlay();
	
}

void ALaunchPad::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	FRotator LaunchRotation = GetActorRotation();
	LaunchRotation.Pitch += 45.0f;

	FVector LaunchVelocity ;
	LaunchVelocity.X = LaunchRotation.Vector().X * DashForce;
	LaunchVelocity.Y = LaunchRotation.Vector().Y * DashForce;
	LaunchVelocity.Z = LaunchRotation.Vector().Z * JumpForce;
	
	
	ACharacter* OtherCharacter = Cast<ACharacter>(OtherActor);

	if(OtherActor != nullptr)
	{
		OtherCharacter->LaunchCharacter(LaunchVelocity,true,true);
	}
}

// Called every frame
void ALaunchPad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

