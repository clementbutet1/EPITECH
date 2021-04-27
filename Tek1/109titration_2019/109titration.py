#!/usr/bin/env python3

##
## EPITECH PROJECT, 2020
## undefined
## File description:
## 109titration
##

import sys
import math
import os
import random

def display_help():
    print("USAGE")
    print("           ./109titration file\n")
    print("DESCRIPTION\n")
    print('           file    a csv file containing "vol;ph" lines')
    sys.exit(0)

def fill_tab(buf):
    tab = buf.readlines()
    if (len(tab) == 0):
        sys.exit(84)
    for i in range(len(tab)):
        if tab[i][len(tab[i]) - 2] == '.':
            print("Invalid line : %s" % tab[i])
            sys.exit(84)
        try:
            tab[i] = tab[i].strip('\n').split(';')
            tab[i][0] = float(tab[i][0])
            tab[i][1] = float(tab[i][1])
        except:
            sys.exit(84)
        if len(tab[i]) != 2:
            print("Invalid line %s" % tab[i])
            sys.exit(84)
    return(tab)

def estimated_derivate(tab, tab2, equi, pnt):
    tab3 = []
    tab4 = []
    start = tab[pnt - 1][0]
    end = tab[pnt + 1][0]
    xa = start
    ya = tab2[pnt - 1]
    xb = equi
    yb = tab2[pnt]
    x = start + 0.1
    print("\nSecond derivative estimated:")
    print("%.1f ml -> %.2f" % (tab[pnt - 1][0], tab2[pnt - 1]))
    tab3.append(tab2[pnt -1])
    tab4.append(tab[pnt - 1][0])
    while x < equi - 0.1:
        if xb - xa == 0:
            sys.exit(84)
        res = ya + (x * ((yb - ya) / (xb - xa)) - (xa * ((yb - ya) / (xb - xa))))
        print("%.1f ml -> %.2f" % (x, res))
        tab3.append(res)
        tab4.append(x)
        x += 0.1
    print("%.1f ml -> %.2f" % (tab[pnt][0], tab2[pnt]))
    tab3.append(tab2[pnt])
    tab4.append(tab[pnt][0])
    x += 0.1
    xa = equi
    ya = tab2[pnt]
    xb = end
    yb = tab2[pnt + 1]
    while x < end - 0.1:
        if xb - xa == 0:
            sys.exit(84)
        res = ya + (x * ((yb - ya) / (xb - xa)) - (xa * ((yb - ya) / (xb - xa))))
        print("%.1f ml -> %.2f" % (x, res))
        tab3.append(res)
        tab4.append(x)
        x += 0.1
    print("%.1f ml -> %.2f" % (tab[pnt + 1][0], tab2[pnt + 1]))
    tab3.append(tab2[pnt])
    tab4.append(tab[pnt + 1][0])
    if tab3[0] < 0:
        tab3[0] *= -1
    j = tab3[0]
    for i in range(len(tab3)):
        if tab3[i] < 0:
            tab3[i] *= -1
        if tab3[i] < j:
            j = tab3[i]
            res = i
    print("\nEquivalence point at %.1f ml" % tab4[res])

def second_derivation(tab, tab1, equi, pnt):
    tab2 = []
    tab2.append(0)
    tab2.append(0)
    print("\nSecond derivative:")
    for i in range(2, len(tab1) - 2):
        Vn = tab[i][0]
        Vbef = tab[i - 1][0]
        Vaft = tab[i + 1][0]
        if (Vn - Vbef == 0.0) or (Vaft - Vbef == 0.0) or (Vaft - Vn == 0.0):
            exit(84)
        res = (((tab1[i] - tab1[i - 1]) / (Vn - Vbef)) * ((Vaft - Vn) / (Vaft - Vbef))) + (((tab1[i + 1] - tab1[i]) / (Vaft - Vn) * ((Vn - Vbef) / (Vaft - Vbef))))
        tab2.append(res)
        print("%.1f ml -> %.2f" % (tab[i][0], res))
    tab2.append(0)
    tab2.append(0)
    estimated_derivate(tab, tab2, equi, pnt)

def derivation(tab):
    tmp = 0.0
    equi = 0
    pnt = 0
    tab1 = []
    print("Derivate:")
    tab1.append(0)
    for i in range(1, len(tab) - 1):
        Vn = tab[i][0]
        Vbef = tab[i - 1][0]
        Vaft = tab[i + 1][0]
        Phn = tab[i][1]
        Phbef = tab[i - 1][1]
        Phaft = tab[i + 1][1]
        if (Vn - Vbef == 0.0) or (Vaft - Vbef == 0.0) or (Vaft - Vn == 0.0):
            exit(84)
        tab1.append((((Phn - Phbef) / (Vn - Vbef)) * ((Vaft - Vn) / (Vaft - Vbef))) + (((Phaft - Phn) / (Vaft - Vn) * ((Vn - Vbef) / (Vaft - Vbef)))))
        print("%.1f ml -> %.2f" % (tab[i][0], tab1[i]))
        if (tmp < tab1[i]):
            tmp = tab1[i]
            equi = tab[i][0]
            pnt = i
    tab1.append(0)
    print("\nEquivalence point at %.1f ml" % equi)
    second_derivation(tab, tab1, equi, pnt)

def main():
    if "--help" in sys.argv or "-h" in sys.argv:
        display_help()
    if (len(sys.argv) != 2):
        sys.exit(84)
    try:
        buf = open(sys.argv[1])
    except:
        print("Invalid file : %s" % sys.argv[1])
        sys.exit(84)
    tab = fill_tab(buf)
    derivation(tab)

if __name__ == '__main__':
    main()
    sys.exit(0)