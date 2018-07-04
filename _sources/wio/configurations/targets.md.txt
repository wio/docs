# Targets Tag
Targets are build units and they are compiled and executed. A wio project can have multiple targets for multiple files, and frameworks. This allows the user to test the codebase for various frameworks, and boards but, also provides an ability to have multiple executables to work with. There are two different types of targets based on the type of wio project user is working with. These are discussed below:

## App Targets
```
targets:
  default: target1
  create:
    target1:
      src: tests/code1
      framework: cosa
      board: uno
      definitions:
        global_definitions:
        - -DMAX_ALLOCATORS=2

    target2:
      src: tests/code2
      framework: cosa
      board: mega
      flags:
        global_flags:
        - -Os
        target_flags:
        - --strip-unneeded
      definitions:
        global_definitions:
        - -DMAX_BLOCKS=45
        - -DNO_WAY
        target_definitions:
        - -DTARGET2          
```


* Targets go under `create` tag as can be seen in the example above where there are two targets: **target1** and **target2**
* `src` tag allows the user to provide a path for executable files. This path is relative to the project path.
* `framework` tag is used to provide the SDK that will be linked with the executable.
* `board` tag is used to provide a board if the platform supports hardware. Otherwise this can be set to "null".
* `global_flags` tag is used to provide flobal glags that are used through out the application and even though the dependency tree. These flags come in handy if there needs to be some global configurations.
* `target_flags` tag is used to provide flags for the target.
* `global_definitions` tag is used to provide global definitions that are used through out the application and even though the dependency tree. These definitions come in handy if there needs to be some global configurations.
* `target_definitions` tag is used to provide definitions for the target.


## Pkg Targets
```
targets:
  default: target1
  create:
    target1:
      src: tests/code1
      framework: cosa
      board: uno
      definitions:
        global_definitions:
        - -DMAX_ALLOCATORS=2

    target2:
      src: tests/code2
      framework: cosa
      board: mega
      flags:
        global_flags:
        - -Os
        target_flags:
        - --strip-unneeded
        pkg_flags:
        - -Wl
      definitions:
        global_definitions:
        - -DMAX_BLOCKS=45
        - -DNO_WAY
        target_definitions:
        - -DTARGET2
        pkg_definitions:
        - PACKAGE2              
```

* Targets go under `create` tag as can be seen in the example above where there are two targets: **target1** and **target2**
* For `pkg` project type, targets are test targets and include the project as a dependency.
* `src` tag allows the user to provide a path for executable files. This path is relative to the project path.
* `framework` tag is used to provide the SDK that will be linked with the executable.
* `board` tag is used to provide a board if the platform supports hardware. Otherwise this can be set to "null".
* `global_flags` tag is used to provide flobal glags that are used through out the application and even though the dependency tree. These flags come in handy if there needs to be some global configurations.
* `target_flags` tag is used to provide flags for the target.
* `pkg_flags` tag is used to provide flags for the package dependency.
* `global_definitions` tag is used to provide global definitions that are used through out the application and even though the dependency tree. These definitions come in handy if there needs to be some global configurations.
* `target_definitions` tag is used to provide definitions for the target.
* `pkg_definitions` tag is used to provide definitions for the package dependency.
