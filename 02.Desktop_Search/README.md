# SPbU Resource Downloader

[![Shell Check](https://github.com/ol-imorozko/SPbU-2023-Tasks/actions/workflows/shellcheck.yml/badge.svg)](https://github.com/ol-imorozko/SPbU-2023-Tasks/actions/workflows/shellcheck.yml)

This script automates downloading educational resources from the St. Petersburg University server

This script is integrated with Recoll --- a powerful desktop search tool that provides full-text search capabilities.

## Installation

**Install Recoll using package managers:**
- For Debian/Ubuntu:
  ```
  sudo apt-get update
  sudo apt-get install recoll
  ```

## Usage

```bash
./import_spbu_umd.bash -s 'https://spbu.ru/sveden/education' -d './folder_to_download_to' [-p]
-s | --source       URL to download from.
-d | --destination  Directory path to save the downloaded files.
-p | --probe        Optional: Download 10 random files if specified.
```

### Basic Search
Perform a basic search with:

```bash
recollq "your search terms"
```
