# DisplaySetter

## Overview
DisplaySetter is a C++ utility designed to manage and restore monitor settings on Windows systems. It sets the monitor layout to "Extend" mode and positions the monitor according to specified `x` and `y` coordinates. This is particularly useful for setups where monitor settings reset after reconnecting monitors or restarting the computer.

## Features
- Automatically sets the display mode to "Extend".
- Configures the x and y positions of monitors based on a configuration file.
- Includes a PowerShell script to detect HDMI connections and automatically launch DisplaySetter.

## Motivation
This project was created to address an issue with resetting monitor settings on a Windows system, particularly when reconnecting an Arzopa S1 monitor or rebooting the computer. DisplaySetter streamlines the process of restoring your preferred display configuration.

## Usage
### Basic Usage
1. Download the precompiled `DisplaySetter.exe` file from the [Releases](https://github.com/krzsmal/DisplaySetter/releases) section or clone the repository and build it from source.
2. Place `DisplaySetter.exe` and `config.ini` in the same directory.
3. Change the `x` and `y` coordinates in `config.ini` to match your preferred monitor layout. You can check the [Example Configurations](#example-configurations) section for more details.
4. Run `DisplaySetter.exe` directly or allow the PowerShell script to handle execution automatically.
5. The display settings will be applied according to the configuration file.
6. You can pin `DisplaySetter.exe` to the Start menu or taskbar, or create a shortcut for easy access.

### Automating with PowerShell
The included PowerShell script, `RunDisplaySetter.ps1`, detects when an HDMI device connects to your computer and runs `DisplaySetter.exe`.

To fully automate the process of running DisplaySetter, follow these steps:
1. Place `RunDisplaySetter.ps1` in the same directory as `DisplaySetter.exe` and `config.ini`.
2. Press `Windows + R` to open the Run dialog.
3. Type `shell:startup` and press Enter to open the Startup folder.
4. Create a new shortcut in the Startup folder:
    - For the location of the item, enter:
      ```powershell
      powershell.exe -ExecutionPolicy Bypass -WindowStyle Hidden -File "path\to\RunDisplaySetter.ps1"
      ```  
    - Name the shortcut: `RunDisplaySetter` or any desired name.
5. Right-click on the shortcut and select `Properties`.
6. In the `Start in` field, specify the folder where `config.ini` is located.
7. Apply the changes and close the properties window.

With these steps, `RunDisplaySetter.ps1` will automatically run on startup, ensuring `DisplaySetter.exe` is triggered when an HDMI device connects.

## Example Configurations
TODO: Add example configurations for different monitor layouts.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
