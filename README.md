Очень маленькая библиотечка для симуляции нажатий написанная на языке C++. 

Для использования библиотеки с C#, вам потребуется перенести <KeybdEvent.dll> в папку с вашей программой и воспользоваться в коде DllImport. 
```csharp
using System.Runtime.InteropServices;
```
Далее набрать этот код:
```csharp
[DllImport("KeybdEvent.dll", CallingConvention = CallingConvention.Cdecl)]
static extern void SendKeyInt(int key);
[DllImport("KeybdEvent.dll", CallingConvention = CallingConvention.Cdecl)]
static extern void KeyPress(int key);
[DllImport("KeybdEvent.dll", CallingConvention = CallingConvention.Cdecl)]
static extern void KeyRelese(int key);
```
