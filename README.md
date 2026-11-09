# World Bank CLI

A C++ command-line application for exploring data from the [World Bank API](https://api.worldbank.org/). It is designed to grow from a simple country browser into a tool for discovering and exploring country and development-indicator data.

## Current capabilities

The application currently fetches the World Bank country list at startup and lets you browse entries by their first letter, with paginated output. Indicator selection, country comparisons, and visualization are possible future extensions, but are not part of the current implementation.

## Features

- Fetches country data from the World Bank API at startup.
- Displays a menu in the terminal.
- Filters country entries by their first letter or lists all entries.
- Shows results in pages of 10, with an option to continue or return to the menu.
- Prints each entry's name and ISO 3166-1 alpha-2 code.

An internet connection is required to fetch data. The program currently uses the API's default country endpoint without specifying a language or data range.

## Project direction

The country browser provides a starting point for working with the World Bank API. Future development may add indicator discovery, fetching indicator values for selected countries, comparing countries over time, and presenting results in tables or visualizations.

## Requirements

- A Windows development environment using MSYS2 UCRT64 (primary workflow)
- An internet connection to retrieve data from the World Bank API

## Windows setup

Install [MSYS2](https://www.msys2.org/) if needed, then open the **MSYS2 UCRT64** terminal and install the compiler and libraries:

```sh
pacman -S --needed mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-curl mingw-w64-ucrt-x86_64-nlohmann-json
```

From that terminal, change to the project directory, build the program, and run it:

```sh
cd /c/code/wbo-cli
./build.sh
./wbo-cli.exe
```

Replace `/c/code/wbo-cli` if the repository is in a different location. The dependencies are installed system-wide in MSYS2 UCRT64; they are not copied into the repository.

## Alternative: Debian or Ubuntu

```sh
sudo apt update
sudo apt install g++ libcurl4-openssl-dev nlohmann-json3-dev
```

Install Bash if it is not already available, then build and run from the repository directory:

```sh
./build.sh
./wbo-cli.exe
```

The build script compiles the C++ sources with C++17, links libcurl, and writes the executable as `wbo-cli.exe`. On other platforms, ensure your compiler, libcurl, and JSON header are discoverable by the compiler and linker.

## Using the CLI
```powershell
.\wbo-cli.exe
```

At the menu, choose **2** to browse the country list or **1** to exit. Enter one letter (for example, `a`) to filter by the first letter, or enter `all` to list all entries. When more than one page is available, enter `n` for the next page; any other response returns to the menu.

## Project structure

| File | Purpose |
|---|---|
| `main.cpp` | Fetches country data and runs the interactive menu. |
| `APIClient.cpp`, `include/APIClient.h` | Retrieves and parses JSON responses using libcurl and nlohmann/json. |
| `parser.cpp`, `include/parser.h` | Extracts country names and ISO2 codes from the API response. |
| `CLI.cpp`, `include/CLI.h` | Implements menu navigation and paginated country browsing. |
| `build.sh` | Compiles the application. |

## Current limitations

- Indicator browsing, comparisons, and plotting are not yet available.
- The application needs a network connection at startup and does not cache API responses.
- API or JSON errors can prevent startup; the current version does not provide an offline mode.

## License

This project is distributed under the [MIT License](LICENSE).
