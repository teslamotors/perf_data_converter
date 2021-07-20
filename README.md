# Introduction

The `perf_to_profile` binary can be used to turn a perf.data file, which is
generated by the linux profiler, perf, into a profile.proto file which can be
visualized using the tool pprof.

For details on pprof, see https://github.com/google/pprof

**THIS IS NOT AN OFFICIAL GOOGLE PRODUCT**

# Prerequisites to build
* Install dependencies

  ```
  sudo apt-get -y install g++ git libelf-dev libcap-dev
  ```
* At least g++-5 or clang-7

# Compile and Test
To install all dependences and build the binary, run the following commands.
These were tested on Ubuntu 14.04 LTS:

### Compile
* Install bazel by following the instructions [here](https://docs.bazel.build/versions/master/install.html).
* Install dependencies and build perf_to_profile using bazel

  ```
  git clone https://github.com/teslamotors/perf_data_converter.git
  cd perf_data_converter
  bazel build src:perf_to_profile
  ```

Place the `perf_to_profile` binary in a place accessible from your PATH (e.g. `/usr/local/bin`).


### Running tests
* There are a small number of tests that verify the basic functionality.
  To run these, after successful compilation, run:

  ```
  bazel test src:all
  bazel test src/quipper:all
  ```

Note: Executables generated using `bazel build` are available under the
directory `bazel-bin/`.

# Usage
* Profile a command using perf, for example:

  ```
  perf record /bin/ls
  ```

* Recent versions of pprof will automatically invoke `perf_to_profile`:

  ```
  pprof -web perf.data
  ```

# Contribution
We appreciate your help!

Note that perf data converter and quipper projects do not use GitHub pull
requests, and that we use the issue tracker for bug reports.
