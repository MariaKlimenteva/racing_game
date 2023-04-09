Package: alsa[core]:x64-linux -> 1.2.6.1#2

**Host Environment**

- Host: x64-linux
- Compiler: GNU 9.4.0
-    vcpkg-tool version: 2023-01-24-8a88d63f241d391772fbde69af9cab96c3c64c75
    vcpkg-scripts version: 54cc53c43 2023-02-23 (3 weeks ago)

**To Reproduce**

`vcpkg install `

**Failure logs**

```
alsa currently requires the following libraries from the system package manager:
    autoconf libtool
These can be installed on Ubuntu systems via sudo apt install autoconf libtool
-- Using cached alsa-project-alsa-lib-v1.2.6.1.tar.gz.
-- Cleaning sources at /home/masha/code_projects/KT_lessons_4/Project_Races/vcpkg/buildtrees/alsa/src/v1.2.6.1-b673b0105e.clean. Use --editable to skip cleaning for the packages you specify.
-- Extracting source /home/masha/code_projects/KT_lessons_4/Project_Races/vcpkg/downloads/alsa-project-alsa-lib-v1.2.6.1.tar.gz
-- Applying patch fix-plugin-dir.patch
-- Using source at /home/masha/code_projects/KT_lessons_4/Project_Races/vcpkg/buildtrees/alsa/src/v1.2.6.1-b673b0105e.clean
-- Getting CMake variables for x64-linux-dbg
-- Getting CMake variables for x64-linux-rel
CMake Error at scripts/cmake/vcpkg_configure_make.cmake:601 (message):
  alsa requires autoconf from the system package manager (example: "sudo
  apt-get install autoconf")
Call Stack (most recent call first):
  ports/alsa/portfile.cmake:44 (vcpkg_configure_make)
  scripts/ports.cmake:147 (include)



```


**Additional context**

<details><summary>vcpkg.json</summary>

```
{
  "name": "vcpkgdemo",
  "version-string": "0.1.0",
  "license": "MIT",
  "dependencies": [
    "spdlog",
    "opengl",
    "glew",
    "glfw3",
    "sdl2",
    "sfml",
    {
      "name": "abseil",
      "features": [
        "cxx17"
      ]
    }
  ]
}

```
</details>
