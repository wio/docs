# Dependencies tag

A goal of Wio has always been to make iot development easier and modular. No more cloning the repository and linking the code. This is achieved by wio package manager. To specify dependencies, `dependencies` tag must be used in `wio.yml` file

```
dependencies:
  pkg1:
    version: 0.0.1
    vendor: false
    link_visibility: PRIVATE
    flags:
    - Os
    definitions:
    - -DNO_WAY

  pkg2:
    version: latest
    vendor: true
    link_visibility: PRIVATE
    flags:
    - Os
    definitions:
    - -DNO_WAY
    dependency_flags:
        transitive1:
        - --strip-unneeded
    dependency_definitions:
        transitive2:
        - -DMAX_SIZE=55
```

* There are mainly two types of dependencies: `vendor` and `remote`. Remote dependencies are pulled from the server and vendor dependencies are placed in `vendor` folder located in the root of the project.
* There are three values available for `linker_visibility`: **PRIVATE**, **PUBLIC** and **INTERFACE**
    * **PRIVATE**: When A links in B as *PRIVATE*, it is saying that A uses B in its implementation, but B is not used in any part of A's public API
    * **INTERFACE**: When A links in B as *INTERFACE*, it is saying that A does not use B in its implementation, but B is used in A's public API
    * **PUBLIC**: When A links in B as *PUBLIC*, it is essentially a combination of **PRIVATE** and **INTERFACE.
    * You can read more about this [here](https://cmake.org/pipermail/cmake/2016-May/063400.html)
* `flags` and `definitions` are applied directly to the dependency
    * Assume *PackageA* has requested definition `-DNUM_BLOCKS` and it's dependency *PackageB* also needs this same definition, user can use placeholder syntax: `$(-DNUM_BLOCKS)`. This will substitute the flag value when requested flag is available.
    * This applies to flags as well
* `dependency_flags` and `dependency_definitions` are flags and definitions to override/provide flags and definitions to all the direct and transitive dependencies for current dependency. There are many uses for this:
    * It allows user to customize the dependency without modifying anything in case it needs to compile those dependencies with different flags/definitions.
    * It allows user to provide debug flags/definitions
        * **Note:** If user is working with **pkg** project, these dependency flags/definitions are not included when someone included current package
