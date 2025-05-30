# Aura game

# Classes
* Base class for characters -> AuraCharacter
  * Class for playable character -> AuraCharacter
  * Class for enemies -> AuraEnemy
* Player classes
  * AuraPlayerController -> player movement and inputs
  * AuraPlayerState -> owner of GAS for player
* Game classes
  * AuraGameModeBase -> setup game modes
* Interaction classes
  * EnemyInterface -> to identify enemies for highlighting outline
* AbilitySystem classes
  * AuraAbilitySystemComponent -> GAS components
  * AuraAttributeSet -> GAS attributes

# Blueprints
  * Player
    * BP_AuraCharacter
      * BP_AuraPlayerController
      * BP_AuraPlayerState
  * Enemies
    * BP_Goblin_Spear
    * BP_Goblin_Slingshot
  * Game
    * BP_AuraGameMode
  * Input
    * InputActions
      * IA_Move

# Info
* Set socket for weapon in skeletal mesh for player and enemies
  * Disable collision for weapon
* Set collision channel for enemies to highlight model outline
  * ECC_Visibility channel
  * ECR_Block response
* Set player fixed camera using camera + spring arm in player blueprint
* Gameplay Ability System (GAS)
  * Add replication mode and frequency to entities for multiplayer
    * Mixed for player for replication
    * Minimal for enemies
  * Initialization
    * Enemies
      * Server -> BeginPlay
      * Client -> BeginPlay
    * Player
      * GAS on Player State
        * Server -> PossessedBy
        * Client -> OnRep_PlayerState
      * GAS on Player Pawn
        * You have to use SetOwner() on the OwnerActor to set the controller 
        * Server -> PossessedBy
        * Client AcknowledgePossession
  * Attribute
    * Need `virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;` to get variable when replicated
    * Need `UPROPERTY(ReplicatedUsing = OnRep_Health)` in the variable we want to replicate
    * Need `FGameplayAttributeData` as variable type
    * Need `UFUNCTION() void OnRep_Health(const FGameplayAttributeData& OldHealth) const;` to replicate the variable