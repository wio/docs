# App Tag

This is the main tag which contains information about the application and it's SDK.
```
name: example
ide: none
```

## Config
This tag contains meta information about what this app supports. This is used to determine tools and matching wio version.
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
This tag contains configurations for all the compile related stuff. At the moment there is only one tag and it is used to specify the platform for the app.
```
compile_options:
    platform: avr
```
