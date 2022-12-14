#!/bin/bash

echo "Usernames currently logged in:"
who | awk '{print $1}'

