#!/bin/bash

# Function to read lines from a file between two line numbers
read_lines() {
  start_line=$1
  end_line=$2
  file=$3
  
  # Validate file existence
  if [ ! -f "$file" ]; then
    echo "Error: File '$file' does not exist."
    exit 1
  fi

  # Validate line numbers
  if [ $start_line -gt $end_line ]; then
    echo "Error: Invalid line numbers."
    exit 1
  fi

  # Read and print lines from the file
  awk "NR >= $start_line && NR <= $end_line" "$file"
}

# Read user input
read -p "Enter the start line number: " start
read -p "Enter the end line number: " end
read -p "Enter the file name: " filename

# Call the function to read lines from the file
read_lines $start $end "$filename"
