<!--
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

-->
