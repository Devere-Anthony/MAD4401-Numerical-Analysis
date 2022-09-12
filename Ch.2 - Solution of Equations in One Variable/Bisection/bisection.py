#!/Users/devere/miniconda3/bin/python3
import os

"""
bisection.py: my implementation of the Bisection method
Author: Devere Anthony Weaver
"""
def f(x):
    """ function to be evaluated (must change with different function) """
    return ((x*x*x) + (4*x*x) - 10)

def bisection(a, b, t, n):
    """ function that implements bisection method algorithm """
    counter = 0
    fa = f(a)
    p = 0
    l = a
    u = b
    print(f"n\ta\t\t\tb\t\t\tp (approx.)\t\t\tf(p)\t\t\t\tError")
    print("__________________________________________________________________________________________________________________________________________")
    while counter < n:
        p = a + (b-a)/2
        fp = f(p)
        if (fp == 0) or ((b-a)/2 < t):    # if exact root found or error tolerance is reached
            counter += 1
            print(f"{counter:>02}\t{a:<16}\t{b:<11}\t\t{p:<16}\t\t{f(p):<16}\t\t{b-p:<16}")
            break
        elif (fa * fp > 0):    # same signs, shift right
            a = p
            fa = fp
        else:    # different signs, shift left
            b = p
        counter += 1
        print(f"{counter:>02}\t{a:<16}\t{b:<11}\t\t{p:<16}\t\t{f(p):<16}\t\t{b-a:<16}")
    print(f"\nAfter {counter} iterations, the approximation for the root in [{l},{u}] is ~{p}\nwith error {b-p}")
    
if __name__ == '__main__':
    while True:
        os.system('cls' if os.name == 'nt' else 'clear')
        print("The Bisection Method\n____________________")
        a = input("Enter a > ")
        b = input("Enter b > ")
        t = input("Enter error tolerance > ")
        n = input("Enter number of iterations > ")
        bisection(float(a), float(b), float(t), int(n))
        cont = input("\nContinue [y/N]? > ")
        if (cont.lower() != 'y'):
            print("\nGoodbye...")
            break
        else: 
            print("\n")
            continue
