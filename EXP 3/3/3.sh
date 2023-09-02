#!/bin/bash

# Function to perform addition
add() {
  sum=$(($1 + $2))
  echo "Result: $sum"
}

# Function to perform subtraction
subtract() {
  diff=$(($1 - $2))
  echo "Result: $diff"
}

# Function to perform multiplication
multiply() {
  product=$(($1 * $2))
  echo "Result: $product"
}

# Function to perform division
divide() {
  if [ $2 -eq 0 ]; then
    echo "Error: Division by zero is not allowed."
  else
    quotient=$(($1 / $2))
    echo "Result: $quotient"
  fi
}

# Read user input
read -p "Enter the operation (+, -, *, /): " operation
read -p "Enter the first number: " num1
read -p "Enter the second number: " num2

# Perform the selected operation
case $operation in
  "+")
    add $num1 $num2
    ;;
  "-")
    subtract $num1 $num2
    ;;
  "*")
    multiply $num1 $num2
    ;;
  "/")
    divide $num1 $num2
    ;;
  *)
    echo "Error: Invalid operation."
    ;;
esac
