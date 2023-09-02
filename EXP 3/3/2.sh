#!/bin/bash

# Check if two arguments are provided
if [ $# -ne 2 ]; then
  echo "Error: Two arguments are required."
  exit 1
fi

# Check if the arguments are valid numbers
re='^[0-9]+$'
if ! [[ $1 =~ $re ]] || ! [[ $2 =~ $re ]]; then
  echo "Error: Invalid input. Arguments must be numeric."
  exit 1
fi

# Convert the arguments to integers
num1=$1
num2=$2

# Print the larger number
if [ $num1 -gt $num2 ]; then
  echo "Larger number: $num1"
else
  echo "Larger number: $num2"
fi

# Add the numbers
sum=$((num1 + num2))
echo "Sum: $sum"

