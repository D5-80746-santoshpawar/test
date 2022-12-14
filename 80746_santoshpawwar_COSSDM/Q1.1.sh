#!/bin/bash

# Get the number of rows from the user
echo "Enter the number of rows:"
read rows

# Loop to iterate through each row
for ((i=1; i<=$rows; i++))
do
    # Loop to print spaces before numbers
    for ((j=1; j<$i; j++))
    do
        echo -n " "
    done
    
    # Loop to print numbers in descending order
    for ((k=$rows; k>=$i; k--))
    do
        echo -n "$k "
    done
    
    # Move to the next line for the next row
    echo ""
done
