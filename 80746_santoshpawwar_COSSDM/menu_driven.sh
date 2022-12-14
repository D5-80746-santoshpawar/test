 #!/bin/bash

while true; do
    echo "-----------------------"
    echo "        Menu           "
    echo "-----------------------"
    echo "1. Print Pattern"
    echo "2. Display Currently Logged-In Users"
    echo "3. Display Terminal Number"
    echo "4. Addition of Floating Point Numbers"
    echo "5. Check Palindrome"
    echo "6. Exit"
    echo "-----------------------"
    
    read -p "Enter your choice (1-6): " choice

    case $choice in
        1)
            read -p "Enter the number of rows for the pattern: " rows
            for ((i = 0; i < rows; i++)); do
                for ((j = 0; j < i; j++)); do
                    printf " "
                done
                for ((k = rows; k > i; k--)); do
                    printf "$k "
                done
                printf "\n"
            done
            ;;
        2)
            who
            ;;
        3)
            tty
            ;;
        4)
            read -p "Enter first floating point number: " num1
            read -p "Enter second floating point number: " num2
            result=$(echo "$num1 + $num2" | bc)
            echo "The addition of $num1 and $num2 is: $result"
            ;;
        5)
            read -p "Enter a string: " input_string
            reversed_string=$(echo "$input_string" | rev)
            if [ "$input_string" == "$reversed_string" ]; then
                echo "The entered string is a palindrome."
            else
                echo "The entered string is not a palindrome."
            fi
            ;;
        6)
            echo "Exiting the script. Goodbye!"
            exit 0
            ;;
        *)
            echo "Invalid choice. Please enter a number between 1 and 6."
            ;;
    esac
done

