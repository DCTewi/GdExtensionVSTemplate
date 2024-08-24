# GdExtensionVSTemplate
This repository serves as a quickstart template for GDExtension development with Godot 4.0+ and Visual Studio.

## Usage

To use this template, log in to GitHub and click the green "Use this template" button at the top of the repository page. This will let you create a copy of this repository with a clean git history. 

For getting started after cloning your own copy to your local machine, you should:

- add `GODOT_DIR` to `PATH` that Visual Studio could find godot-cpp header and libraries.
- change the name of your library.
	- change the name of subdirectory
	- change the name of .vcxproj file
	- change the name of `template.gdextension` and the libraries name in `template.gdextension`
- open the .vcxproj to generate a .sln file for you
- register the classes you want Godot to interact with inside the `register_types.cpp` file in the initialization method (here `init_module`) in the syntax `godot::ClassDB::register_class<CLASS-NAME>();`

## Build

By default your build will be in `$(SolutionDir).build\`. The structure of default build is:

```
.build
│  
├─addons
│  └─GdExtensionVSTemplate
│      template.gdextension
│          
└─bin
    .gdignore
    libGdExtensionVSTemplate.x64.Debug.dll
    libGdExtensionVSTemplate.x64.Debug.pdb
```

You can copy all content to your `project.godot` path. Or change the `$(OutDir)` directly.

## Configuration of GODOT_DIR

Here is the expected structure that `GODOT_DIR` should have:

```
GODOT_DIR
│  godot.exe
│  
├─GodotCpp
│  ├─include
│  │  │  gdextension_interface.h
│  │  │
│  │  └─godot_cpp
│  │      │  godot.hpp
│  │      │
│  │      ├─classes
│  │      ├─core
│  │      ├─templates
│  │      └─variant
│  └─lib
│      libgodot-cpp.windows.editor.x86_64.lib
│      libgodot-cpp.windows.template_debug.x86_64.lib
│      libgodot-cpp.windows.template_release.x86_64.lib
│
└─GodotSharp
    ├─Api
    └─Tools
```

By specifying different `GODOT_DIR`, you can easily build your GDExtension with different versions and custom forks of Godot.

Some install snippets:

```powershell
$env:GODOT_INSTALL_DIR = "<PATH_TO_GODOT_DIR>\GodotCpp\"

if (Test-Path -Path $env:GODOT_INSTALL_DIR) {
    rm -r -force $env:GODOT_INSTALL_DIR
} else {
    mkdir $env:GODOT_INSTALL_DIR
}

xcopy /s/y bin\*.lib "$($env:GODOT_INSTALL_DIR)lib\"
xcopy /s/y gen\include\ "$($env:GODOT_INSTALL_DIR)include\"
xcopy /s/y include\ "$($env:GODOT_INSTALL_DIR)include\"
xcopy /s/y gdextension\gdextension_interface.h "$($env:GODOT_INSTALL_DIR)include\"
```

