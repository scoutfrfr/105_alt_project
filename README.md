# CMP105 2024 Final Submission 

## Game 

**_Dino Handyman: Now with weapons!_** 

_Dino Handyman:Now with weapons! is a 2D platformer which takes place over 4 levels, the player must use their platforming skills along with abilities (to double jump and wield a weapon) to get to the end of the game!_

**Controls:** 

A/D to move left/right,

spacebar to jump (tap again whilst in air to double jump when ability is unlocked),

B to attack,

F to interact with flags/levers,

left-click to select menu options,

escape to pause.

## Student Details

**Student Name:** Scout Botha

**Student Number:** 2502470

**Course:** _CGAD_ 

## Changelist
_The changes you have made since the group submission._

**Enemies:**
* Enemies have been added in the form of another dinosaur, damages player upon collision and dies when colliding with     player attacking.

**Weapon Added:**
* Player can now attack enemies using a weapon. 

**Pause Added:**
* Player can now pause the game 

**Two New Levels:**
* There are now two additional levels added to the game.

## Known Bugs

* Sometimes buttons do not work when full screen, minimise screen then click the button and it should work.


---
---

# Proposal from March

## Game Extended

Dino Handyman

William Kavanagh

## Title of Extension

Dino Handyman: Now with weapons!

_note any changes from the original proposal clearly (e.g., **new:** I will add one level.  ~~I will add two levels.~~)

## Brief Overview of game 

Dino Handyman: Now with weapons!, will be a single player platformer where the player controls a small dinosaur and will have to platform across levels filled with hazards and enemies, each level is structured in a way that the player must use all of their unlocked abilities in order to move on to the next level. The player must also beat the level without dying otherwise they will have to restart the level. The player unlocks various abilities throughout the game (i.e, double jump, dash, attack). The initial weapon the player unlocks is found within a level, later weapons can be unlocked via purchasing them from the shop with shards (The currency used in the game). The player has the option within the levels to save baby dinosaurs that have yet to hatch from their eggs and return them to the shop-keeper or to crush them to gain more shards. This affects the morality system of the game and dictates the ending the player gets.

## Must Have Features

✅ Enemies: Enemies will be added to the game in the form of another species of dinosaur (species undecided). 
**new:** Enemies are stood in place and act as a hazard the player can either avoid or destroy by using their weapon. ~~These will charge towards the player once they are close enough~~ and upon collision will cause the player to lose one health point. Upon collision with the players weapon, they will be despawned.

✅ Weapon system: **new:** Player has a weapon throughout the game that they can use to destroy enemies. ~~The player can now use weapons after gaining the ability to wield weapons which will be given within a level. After the weapon wielding ability is unlocked the player can spend shards to unlock different weapon types. Weapons can be equipped within the players inventory.~~

✅ Pause Screen: **new:** A pause menu which freezes the game when escape is pressed and unfreezes when escape is pressed again. ~~A pause menu with simple text to show to the player that the game is paused~~. Music will either be stopped or lowered in volume when paused and will resume as normal alongside the game when the player unpauses.

## Should Have Features

Data Driven Level Loading: Implemented to create various levels without having a huge block of code. Makes code more clean and makes thing easier in the long run (gives the ability to add more levels more easily).

✅ Health System: The player has three lives. These can be lost by falling off the map, into hazards or colliding with enemies. If the player loses all three lives they will have to restart the level they are currently on.

Morality System: The player has the option to either save dinosaur eggs and return them to the shop-keeper or destroy them in order to gain more shards that can be traded for weapons. Once you destroy a certain amount of eggs the shop-keeper will catch on which will lead the player to the bad ending of the game, whereas if you return a certain amount of eggs the shopkeeper will pay you back with shards and you will be on track to get the good ending of the game as long as you do not destroy any eggs.

Shop: The player visits the shop between levels and is given the option to purchase weapons with shards they collect through the levels. This is also where the player returns the eggs if they choose to rescue them. Will just be a menu with the option to talk to shop keeper, return eggs or purchase weapons between levels unless HUB area is implemented (see under "Wish to Have Features).

## Could Have Features

Controller Implementation: The ability to use controller to play the game instead of keyboard to give players a different way of playing.

Input Buffer: Registers inputs before they can be performed and stores them until they can be (i.e if the player tries to jump just before they land, they will jump once they are back on the ground) will make the game feel more responsive.

✅ Heads-Up-Display: Shows the amount of lives the player has, ~~the weapon that is equipped, current level and the time taken on the level on the screen~~.

## Wish to Have Features

Leaderboard: Players time spent on levels is written to file and then displayed on a leaderboard along with the best times. Adds replayability to the game in order to achieve the best score.

Ability to equip multiple weapons: The player can equip two weapons in their inventory then switch between them in levels to use what weapons they feel would best suit the scenario they are in.

Hub area: An area with different NPCs to talk to (could affect morality system), would also be where the shop is located rather than just going directly there between levels. Would have a practise area for player to test their weapons/abilities. The player can also use this to access previous levels rather than having to replay the whole game.

Flying enemies: Different enemy type (likely pterodactyl) that flies along a set path that the player must either carefully platform around or defeat in order to pass. Adds variety to the enemies within the game so it doesn't feel as repetitive.

Gimmick Levels: Levels which revolve around an ability the player can only use in this particular level, i.e gravity manipulation, time stopping/slowing, underwater level (ability to breath under water), rhythm based platforming.

