#!/bin/bash
cut -d ';' -f 3 | grep -Fci "${1}"
