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

# Pipe output to less for paging (preserves colors)
./grab "error" log.txt | less -R