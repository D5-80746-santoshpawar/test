#!/bin/bash

echo -n "Enter a string: "
read original

# Remove spaces and convert to lowercase for a case-insensitive comparison
cleaned=$(echo "$original" | tr -d ' ' | tr 'A-Z' 'a-z')

# Reverse the string
reversed=$(echo "$cleaned" | rev)

# Check if the original and reversed strings are the same
if [ "$cleaned" == "$reversed" ]; then
    echo "The entered string is a palindrome."
else
    echo "The entered string is not a palindrome."
fi

