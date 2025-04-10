# Debug stubs download with Alif Security Toolkit

On Ensemble devices the debug probe connection to the target core is only possible if the target core boots a valid application and therefore, initially a debug stub application must be loaded to the Ensemble device using Alif Security Toolkit (SETOOLS).

This directory contains debug stubs and JSON configuration files that shall be used with SETOOLS to generate and download application stubs that allow debug probe connection.

## Directory structure

Directory                      | Description
:------------------------------|:--------------
[build/config](./build/config) | JSON configuration files.
[build/images](./build/images) | Binaries containing application stubs.

One can copy `build` directory into SETOOLS installation root.

## Debug M55_HE (single core)

To develop application using M55_HE one must generate and download debug stubs by executing the following commands from the command window:

    app-gen-toc -f .\build\config\mram_he.json
    app-write-mram -p

This configuration allows the available MRAM memory space to be used by M55_HE.

## Debug M55_HP (single core)

To develop application using M55_HP one must generate and download debug stubs by executing the following commands from the command window:

    app-gen-toc -f .\build\config\mram_hp.json
    app-write-mram -p

This configuration allows the available MRAM memory space to be used by M55_HP.

## Debug M55_HP and M55_HE (dual core)

To develop application using M55_HP and M55_HE simultaneously (dual core configuration) one must generate and download debug stubs by executing the following commands from the command window:

    app-gen-toc -f .\build\config\mram_hp_he.json
    app-write-mram -p

This configuration splits the available MRAM memory space between M55_HP and M55_HE:

CPU    | Boot Address
:------|:--------------
M55_HE | 0x80000000
M55_HP | 0x80200000

## Further read

Refer to "Alif Security Toolkit User Guide" for more information.
