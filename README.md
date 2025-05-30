# Aura game

# Classes
* Base class for characters -> AuraCharacter
<br>
  * Class for playable character -> AuraCharacter
  * Class for enemies -> AuraEnemy
<br>
<br>
* Player classes
<br>
  * AuraPlayerController -> player movement and inputs
    <br>
  * AuraPlayerState -> owner of GAS for player
<br>
<br>
* Game classes
<br>
  * AuraGameModeBase -> setup game modes
<br>
<br>
* Interaction classes
<br>
  * EnemyInterface -> to identify enemies for highlighting outline
<br>
<br>
* AbilitySystem classes
<br>
  * AuraAbilitySystemComponent -> GAS components
<br>
  * AuraAttributeSet -> GAS attributes
<br>
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