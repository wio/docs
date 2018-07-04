# Pkg Tag

This is the main tag which contains information about the package and it's SDK.
```
ide: none
```

## Meta
This tag contains all the information related to publishing the package.
```
meta:
    name: example
    description: A wio avr pkg using cosa framework
    version: 0.0.1
    author: ""
    contributors: []
    keywords:
    - avr
    - c
    - c++
    - wio
    - cosa
    license: MIT
```

All the tags above are required for the project to be published but, `repository` and `organization` tags can be added to specify more information about the package.

## Config
This tag contains meta information about what this package supports. This is important when an app or package uses this package as a dependency because this is used to check compatibility. If package is not compatible, it is not included in the build process.
```
config:
    minimum_wio_version: 0.3.2
    supported_platforms:
    - avr
    supported_frameworks:
    - cosa
    supported_boards:
    - uno
```

* `supported_platforms` tag is used to specify all the platforms this app supports. This means that it can be compiled for that platform
* `supported_frameworks` tag is used to specify all the frameworks this app supports. This means that it can be compiled using libraries from that framework.
* `supported_boards` tag is used to specify the hardware supported by this application. This will be used when uploading application code.

All these `supported` tags have their `unsupported` compliment tags which do the inverse. Any platform, framework and board specified there will be unsupported in the build process.

## Compile Options
This tag contains configurations for all the compile related stuff. It let's user provide flags, definitions and also request certain flags and definitions before project is compiled.
```
compile_options:
    header_only: false
    platform: avr
  flags:
    allow_only_global_flags: false
    allow_only_required_flags: false
    global_flags: []
    required_flags: []
    included_flags: []
    visibility: PRIVATE
  definitions:
    allow_only_global_definitions: false
    allow_only_required_definitions: false
    global_definitions: []
    required_definitions: []
    included_definitions: []
    visibility: PRIVATE
```

* `header_only` tag defined if the package is header only or it contains source files. If this flag is not properly set, it can cause many compile issues
* `platform` tag is crucial to define the platform this package supports
* Flags:
    * `allow_only_global_flags` tag is used when this package only accepts global flags and rejects all other flags.
    * `allow_only_required_flags` tag is used when this package only accepts required flags and rejects all other flags. **Note:** If both `allow_only_global_flags` and `allow_only_required_flags` are set to true, only global flags are used.
    * `global_flags` tag is an array of global flags requested by the package. These flags have to be defined by the app using this package for the app to compile.
    * `required_flags` tag is an array of flags requested by the package. These flags have to be defined by the parent of this package in the dependency tree. If at any moment in dependency tree, these requirements are not met, there is a compile error.
    * `included_flags` tag is an array of flags that are included for the package in the build process. No requirements are needed to met.
* Definitions:
    * `allow_only_global_definitions` tag is used when this package only accepts global definitions and rejects all other definitions.
    * `allow_only_required_definitions` tag is used when this package only accepts required definitions and rejects all other definitions. **Note:** If both `allow_only_global_definitions` and `allow_only_required_definitions` are set to true, only global definitions are used.
    * `global_definitions` tag is an array of global definitions requested by the package. These definitions have to be defined by the app using this package for the app to compile.
    * `required_definitions` tag is an array of definitions requested by the package. These definitions have to be defined by the parent of this package in the dependency tree. If at any moment in dependency tree, these requirements are not met, there is a compile error.
    * `included_definitions` tag is an array of definitions that are included for the package in the build process. No requirements are needed to met.
* `visibility` tag is used to specify the visbility of flags and definitions in the build process. Available options are:
    * **PUBLIC**: These flags/definitions will have public scope
    * **PRIVATE**: These flags/definitions will have private scope
    * **INTERFACE**: These flags/definitions are used for header only package
