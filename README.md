
# ObstacleAssault 

Developed with Unreal Engine 5


### Modules are missing error fix

`That basically means you should rebuild as you likely updated Visual Studio or Unreal.  Use the rebuild build task from VS Code
<br>
Ctrl + Shift + B > ProjectNameEditor Platform Development Rebuild.
<br>
Where ProjectName is the name of your project and Platform is the platform you're targeting e.g. Win64
<br>
Or delete your project's Binaries and Intermediate folders then you'll be prompted to rebuild upon attempting to open the project.`

Using Structs in C++
=

`Constructor` - Makes a new struct or class value
<br>
A constructor in C++ is a special method that is automatically called when an object of a class is created.
<br>
To create a constructor, use the same name as the data type, followed by parentheses ()

```cpp
UPROPERTY(EditAnywhere)
FVector MyFloat = FVector(1,2,3); // Constructor
```

`Operators` - Symbols that do something
<br>
Operators are used to perform operations on variables and values.
<br>
e.g. `+,-.=.*,/`
<br>
`Dot Operator` - Gets something from within a struct or class
<br>
### Game Loop

1. Process Input
2. Update games state
3.  Render to display

- `Frame` - a single picture in a video
- `Frame rate` - how many frames per second(FPS)
- `Tick` - called every frame

### Scope

- How long does the variable live?
- Generally between {} braces

### Write Pseudocode with comments

- Pseudocode- plain language description of the steps in an algorithm.

### Functions

- Expression- fragment of code that produces a value

```cpp
MyVector
LocalVecor.Z + 100
GetActorLocation()
```

- Statement - an action to be performed

```cpp
FVector CurrentLocation = GetActorLocation();
```

### Using DeltaTime

- Using `DeltaTime` Unreal can tell us how long each frame took to execute
- When we multiply something by DeltaTime it makes our game "frame rate independent".
- ie the game behaves the same on fast and slow computers


Each second move 1 unit to the left

| | slow computer 🖥️ | fast computer 🖥️ |
|--|--------------|-------------|
|Frames per second| 10   | 100 |
|Duration of frame | 0.1s | 0.01s |
|Distance per second| 1 x 10 x 0.1 = 1| 1 x 100 x 0.01 = 1

- Scope Resolution Operator- (::) Looks inside a class

### [Vector normal](https://dev.to/fkkarakurt/matrices-and-vectors-in-game-development-67h)

A normal refers to a unit-length vector

- [GetSafeNormal](https://docs.unrealengine.com/4.26/en-US/API/Runtime/Core/Math/FVector/GetSafeNormal/)

```cpp
FVector GetSafeNormal
(
    float Tolerance
)  const
```

Gets a normalized copy of the vector, checking it is safe to do so based on the length. Returns zero vector of vectr length is too small to safely normalize.

[Game Mode and  Game State](https://docs.unrealengine.com/5.0/en-US/setting-up-a-game-mode-in-unreal-engine/)
=

- The GameMode defines the game's set of rules. The rules can include how players join the game, game pausing, and level transition, as well as any game-specific behavior such as win conditions. The GameMode is set for each level, and GameModes can be reused in multiple levels.

Output logs
=

- Using `Unreal Engine 4 Snippets`
    ```cpp
    ulog
    ```
- [Logging](https://docs.unrealengine.com/5.0/en-US/API/Runtime/Core/Logging/)
- [Logging](https://unrealcommunity.wiki/logging-lgpidy6i) means keeping an ordered record of events, function calls, variable values at certain time during runtime, etc. This is usually saved in the form of text in a log file.

- Syntax

```cpp
UE_LOG(LogTemp, Warning, TEXT("Hello"));
```

[FString](https://docs.unrealengine.com/4.26/en-US/ProgrammingAndScripting/ProgrammingWithCPP/UnrealArchitecture/StringHandling/FString/)
=

```cpp
//Creating FStrings
FString TestHUDString = FString(TEXT("This is my test FString."));
```

Conversions
-

| __From__ | __To__ | __Example__|
|-|-|-|
|Fstring| FNamae|TestHUDName = FName(*TestHUDString); <br> _FString -> FName is dangerous as the conversion is lossy as FName's are case insensitive._
|FString|FText|TestHUDText = FText::FromString(TestHUDString); <br> _FString -> FText is valid in some cases, but be aware that the FString's content will not benefit from the FText's "auto localization"._