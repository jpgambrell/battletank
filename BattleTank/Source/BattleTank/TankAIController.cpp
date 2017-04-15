// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("where my mf player??"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Tank Mother Fucker found Player!: %s"), *PlayerTank->GetName());
	}
	
}

ATank* ATankAIController::GetAIControlledTank() const {
	UE_LOG(LogTemp, Warning, TEXT("Get Tank Pawn"));
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() {
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}