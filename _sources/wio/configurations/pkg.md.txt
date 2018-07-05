# Pkg Tag
This is the main tag under which all other tags are. It contains information about extra build plugins.
```
ide: none
```

```eval_rst
+---------------+-------------------------------------------------------------------------------------------+
| **Tag Names** | **Tag Description**                                                                       |
+---------------+-------------------------------------------------------------------------------------------+
| ide           | IDE/test editor supported by wio to help with build process (not supported at the moment) |
+---------------+-------------------------------------------------------------------------------------------+
```

## Meta
This is metadata for the package. When a package is published, this information is used.
```
meta:
    name: example
    description: A wio avr pkg using cosa framework
    version: 0.0.1
    author: John Example <john@example.com> (https://github.com/johnexample)
    contributors: []
    keywords:
    - avr
    - c
    - c++
    - wio
    - cosa
    license: MIT
```

* All the tags above are required for the project to be published but, `repository` and `organization` tags can be added to specify more information about the package.
* **`author`** and **`contributors`** format is exactly like npm format is. You can read more about it on [this website](https://docs.npmjs.com/files/package.json#people-fields-author-contributors).

## Config
Metadata information for the package that is used to provide information about the package to wio especially when this package is used as dependency. If package is not compatible based on this metadata, it is not included in the build process
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
This contains information that is used for compile process. When build process is triggered, information is used from here. All the flags and definitions are requested here.
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

```eval_rst
+---------------+---------------------------------------------------------------+
| **Tag Names** | **Tag Description**                                           |
+---------------+---------------------------------------------------------------+
| header_only   | Specify if the package is header only                         |
+---------------+---------------------------------------------------------------+
| Platform      | Platform being used to compile a test target for the package. |
+---------------+---------------------------------------------------------------+
```

```eval_rst
+---------------------------+-------------------------------------------------------------------------------------+
| **Tag Names**             | **Tag Description**                                                                 |
+---------------------------+-------------------------------------------------------------------------------------+
| allow_only_global_flags   | Making this true will make the package only accept global flags                     |
+---------------------------+-------------------------------------------------------------------------------------+
| allow_only_required_flags | Making this true will make the package only accept required flags                   |
+---------------------------+-------------------------------------------------------------------------------------+
| global_flags              | A list of global flags requested by the package to be included in the build process |
+---------------------------+-------------------------------------------------------------------------------------+
| required_flags            | A list of flags required for package to be compiled                                 |
+---------------------------+-------------------------------------------------------------------------------------+
| included_flags            | A list of flags injected into the build process by the package                      |
+---------------------------+-------------------------------------------------------------------------------------+
```
* if both `allow_only_global_flags` and `allow_only_required_flags` are set to true, only global flags are used.

```eval_rst
+---------------------------------+-------------------------------------------------------------------------------------------+
| **Tag Names**                   | **Tag Description**                                                                       |
+---------------------------------+-------------------------------------------------------------------------------------------+
| allow_only_global_definitions   | Making this true will make the package only accept global definitions                     |
+---------------------------------+-------------------------------------------------------------------------------------------+
| allow_only_required_definitions | Making this true will make the package only accept required definitions                   |
+---------------------------------+-------------------------------------------------------------------------------------------+
| global_definitions              | A list of global definitions requested by the package to be included in the build process |
+---------------------------------+-------------------------------------------------------------------------------------------+
| required_definitions            | A list of definitions required for package to be compiled                                 |
+---------------------------------+-------------------------------------------------------------------------------------------+
| included_definitions            | A list of definitions injected into the build process by the package                      |
+---------------------------------+-------------------------------------------------------------------------------------------+
```
* if both `allow_only_global_definitions` and `allow_only_required_definitions` are set to true, only global definitions are used.

```eval_rst
+---------------+------------------------------------------------------+
| **Tag Names** | **Tag Description**                                  |
+---------------+------------------------------------------------------+
| visibility    | Visibility of flags and definitions in build process |
+---------------+------------------------------------------------------+
```

Visibility options allowed are:
* **PUBLIC**: These flags/definitions will have public scope
* **PRIVATE**: These flags/definitions will have private scope
* **INTERFACE**: These flags/definitions are used for header only package

You can read more about flags and definitions in the flags section.