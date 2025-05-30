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
<br>
<br>
* Set collision channel for enemies to highlight model outline
  * ECC_Visibility channel
  * ECR_Block response
<br>
<br>
* Set player fixed camera using camera + spring arm in player blueprint
<br>
<br>
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
        * Server -> PossessedBy
        * Client AcknowledgePossession