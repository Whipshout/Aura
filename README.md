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

# Attributes
* Primary attributes
  * Strength -> increases physical damage
  * Intelligence -> increases magical damage
  * Resilience -> increases armor and armor penetration
  * Vigor -> increases health
* Secondary attributes
  * Armor -> reduces damage taken, improves Block Chance
    * Depends on -> Resilience
  * Armor Penetration -> ignores percentage of enemy Armor, increases Critical Hit Chance
    * Depends on -> Resilience
  * Block Chance -> chance to cut incoming damage in half
    * Depends on -> Armor
  * Critical Hit Chance -> chance to double damage plus Critical Hit Bonus
    * Depends on -> Armor Penetration
  * Critical Hit Damage -> bonus damage added when a critical hit is scored
    * Depends on -> Armor Penetration
  * Critical Hit Resistance -> reduces critical hit chance of attacking enemies
    * Depends on -> Armor
  * Health Regeneration -> amount of Health regenerated every 1 second
    * Depends on -> Vigor
  * Mana Regeneration -> amount of Mana regenerated every 1 second
    * Depends on -> Intelligence
  * Max Health -> maximum amount of Health obtainable
    * Depends on -> Vigor
  * Max Mana -> maximum amount of Mana obtainable
    * Depends on -> Intelligence
* Vital attributes
  * Health
  * Mana

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