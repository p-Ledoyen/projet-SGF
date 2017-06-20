#!/bin/bash

gcc "shell.c" -o "shell"
gnome-terminal -e "./shell"
