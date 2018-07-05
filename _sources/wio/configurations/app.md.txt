# App Tag
This is the main tag under which all other tags are. It contains information about the name and extra build plugins.

```
name: example
ide: none
```

```eval_rst
+---------------+-------------------------------------------------------------------------------------------+
| **Tag Names** | **Tag Description**                                                                       |
+---------------+-------------------------------------------------------------------------------------------+
| ide           | IDE/test editor supported by wio to help with build process (not supported at the moment) |
+---------------+-------------------------------------------------------------------------------------------+
```

## Config
Metadata information for the application that is used to provide information about the application to wio.
```
config:
    minimum_wio_version: 0.3.2
    supported_platforms:
    - avr
    supported_frameworks:
    - cosa
    supported_boards:
    - uno
    unsupported_boards:
    - mega2560
```

```eval_rst
+------------------------+----------------------------------------------+
| **Tag Names**          | **Tag Description**                          |
+------------------------+----------------------------------------------+
| supported_platforms    | Platforms supported by this application      |
+------------------------+----------------------------------------------+
| support_frameworks     | Frameworks supported by this application     |
+------------------------+----------------------------------------------+
| supported_boards       | Boards supported by this application         |
+------------------------+----------------------------------------------+
| unsupported_platforms  | Platforms not supported by this application  |
+------------------------+----------------------------------------------+
| unsupported_frameworks | Frameworks not supported by this application |
+------------------------+----------------------------------------------+
| unsupported_boards     | Boards not supported by this application     |
+------------------------+----------------------------------------------+
```

* There is a special keyword: **`all`** that can be used for all the `supported` tags to specify that this application supports eveything under that category.
* If only `unsupported` tag is provided for a category, then everything under that category is supported besided what is specified as unsupported.

## Compile Options
This contains information that is used for compile process. When build process is triggered, information is used from here.
```
compile_options:
    platform: avr
```

```eval_rst
+---------------+---------------------------------------------------------------+
| **Tag Names** | **Tag Description**                                           |
+---------------+---------------------------------------------------------------+
| platform      | Platform being used to compile a test target for the package. |
+---------------+---------------------------------------------------------------+
```
