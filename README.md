# GRAB Tool

A grep-like tool created by Nikola Horvat.  
Simplified version with essential functionality.

## Usage

```bash
./grab {pattern} {filename} [options]


# Basic search with colored output
./grab "search_term" file.txt --color red

# Search without line numbers
./grab "pattern" data.log -c blue --no-line-numbers

# Multifile search
./grab "pattern" -fc/--file-count "file-count" file1.file file2.file
