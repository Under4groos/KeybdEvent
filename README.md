
[![Dowland](https://i.imgur.com/AnxsELS.png)](https://github.com/Under4groos/KeybdEvent/raw/main/x64/Release/KeybdEvent.dll?raw=true)
Очень маленькая библиотечка для симуляции нажатий написанная на языке C++. 

Для использования библиотеки с C#, вам потребуется перенести <KeybdEvent.dll> в папку с вашей программой и использовать в коде DllImport. 
```csharp
using System.Runtime.InteropServices;
```
Далее набрать этот код:
```csharp
/// <summary>
/// Зажимает и отпускает клавишу <int key>. 
/// </summary>
/// <param name="key"></param>
[DllImport("KeybdEvent.dll", CallingConvention = CallingConvention.Cdecl)]
static extern void SendKeyInt(int key);
/// <summary>
/// Зажимает клавишу <int key>. 
/// </summary>
/// <param name="key"></param>
[DllImport("KeybdEvent.dll", CallingConvention = CallingConvention.Cdecl)]
static extern void KeyPress(int key);
/// <summary>
/// Отпускает клавишу <int key>. 
/// </summary>
/// <param name="key"></param>
[DllImport("KeybdEvent.dll", CallingConvention = CallingConvention.Cdecl)]
static extern void KeyRelese(int key);
```
Пример рабочего кода:
```csharp
KeyPress((int)System.Windows.Forms.Keys.P);
Thread.Sleep(400);
KeyRelese((int)System.Windows.Forms.Keys.P);
Thread.Sleep(400);
```
