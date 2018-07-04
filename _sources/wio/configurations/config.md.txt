# Project Configuration

The project configuration file is named `wio.yml`. This is a [yaml-style](https://en.wikipedia.org/wiki/YAML) file.

`wio.yml` has various sections denoted by a key and then under that there are more key and value pairs. Lines begin with `#` are ignored and are treated as comments.

An array of values are specified like this:
```yaml
tagName:
- value 1
- value 2
```

Wio uses a concept of `app` and `pkg` and hence there are two types of `wio.yml` files that are created based on the type of the project. All the tags are discussed below:

```eval_rst
.. toctree::
	:maxdepth: 4
	
	app
	pkg
	targets
	dependencies
```

## Examples

### App wio.yml
```
app:
  name: example
  ide: none

  config:
    minimum_wio_version: 0.3.2
    supported_platforms:
    - avr
    supported_frameworks:
    - cosa
    supported_boards:
    - uno

  compile_options:
    platform: avr

targets:
  default: main
  create:
    main:
      src: src
      framework: cosa
      board: uno

dependencies:
  package1:
    version: 0.0.1
```


### Pkg wio.yml
```
pkg:
  ide: none

  meta:
    name: example
    description: A wio avr pkg using cosa framework
    version: 0.0.1
    keywords:
    - avr
    - c
    - c++
    - wio
    - cosa
    license: MIT

  config:
    minimum_wio_version: 0.3.2
    supported_platforms:
    - avr
    supported_frameworks:
    - cosa
    supported_boards:
    - uno

  compile_options:
    platform: avr

targets:
  default: tests
  create:
    tests:
      src: tests
      framework: cosa
      board: uno

dependencies:
  package1:
    version: 0.0.1
```
