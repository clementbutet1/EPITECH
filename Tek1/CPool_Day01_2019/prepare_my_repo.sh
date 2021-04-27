#!/bin/bash
blih -u clement.butet@epitech.eu repository create $1
blih -u clement.butet@epitech.eu repository setacl $1 ramassage-tek r 

git clone git@git.epitech.eu:/clement.butet@epitech.eu/$1


