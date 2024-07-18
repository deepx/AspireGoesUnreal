# AspireGoesUnreal

## Introduction

**AspireGoesUnreal** is a powerful tool that allows the Unrealengine to leverage the capabilities of the .NET Aspire framework. This plugin is designed to provide a seamless integration between Unreal Engine and .NET Aspire, enabling developers to create more complex and robust games and applications.

> [!NOTE]
> Actual this Plugin is tested on Windows 11 with UnrealEngine `5.4` and .NET Aspire `8.0.1` or higher.
It should work with all Unrealengine 5 Versions. Please let me know.

## Features

- Seamless integration with Unreal Engine.
- Access to all(in work) the functionalities of .NET Aspire.
- Easy to use and integrate into your existing Unreal Engine project.
- Works with the UnrealEditor or with a dedicated Server

## Installation

1. Download the .NET Aspire Plugin from the repository.
   - Or clone the the Repository direcly into your `Plugins` folder.
2. Extract the downloaded file into the `Plugins` folder of your Unreal Engine project.
3. Restart your Unreal Engine editor. The plugin should now be available in the `Plugins` window under the `Installed` section.
4. Add the following Lines to the AppHost of your Aspire-Project to include the Unrealengine-Editor

```
var unrealEditor = @"Path to your UnrealEditor.exe";  // With Filename
var workingDirectory = @"Directory of your UnrealEngine-Project";
string[] parameter = [@"Path to the UPROJECT File of your Project"];  // With Filename
var unrealGame = builder.AddExecutable("UnrealGame", unrealEditor, workingDirectory, parameter);
```

## Usage

After installing the plugin, you can access .NET Aspire functionalities from your Unrealengine-Project.
Klick on the Screenshot below to open the Video on Youtube.

[![Video Title](https://img.youtube.com/vi/u43sRzUpY8Y/0.jpg)](https://www.youtube.com/watch?v=u43sRzUpY8Y)

## Support

If you encounter any issues or have any questions, please open an issue on this repository. We will do our best to help you out.

## License

This project is licensed under the MIT License. See the `LICENSE` file in the project root for more information.

#### Todo:
- [X] Get Aspire-Services
- [X] Get ConnectionStrings
- [ ] Add Opentelemetry-Exporter
- [ ] Add support for Websockets
- [X] Add logging to Aspire
- [ ] Make it usable to Windows, Linux and Mac

## Acknowledgements

We would like to thank:

- The Unreal Engine team for creating such a powerful game engine.
- The .NET Aspire team for their great framework.
- [Aspireify.net](https://aspireify.net/a/240517/aspire-goes-unreal) ( @csharpfritz ) for publishing
- All contributors who have helped to improve this plugin.

