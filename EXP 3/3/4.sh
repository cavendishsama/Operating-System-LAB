#!/bin/bash

# Function to reverse a number
reverse_number() {
  number=$1
  reversed=""
  
  while [ $number -gt 0 ]; do
    remainder=$((number % 10))
    reversed="${reversed}${remainder}"
    number=$((number / 10))
  done

  echo "Reversed number: $reversed"
}

# Read user input
read -p "Enter a number: " num

# Call the function to reverse the number
reverse_number $num
