#!/usr/bin/env python3

import os
import sys
import subprocess

# rough script to quickly grade for provided test cases

def main(argv):
    if (not len(argv)): return
    if (len(argv) > 1):
        if (argv[0] == "-c"):
            files = os.listdir(argv[1] + "/src")
            for file in files:
                if (".java" not in file): return
                directory = argv[1] + "/src/" + file
                subprocess.run(["./codegen", directory], stderr=subprocess.PIPE)
    else:
        files = os.listdir(argv[0] + "/src"); score = 0; filesAssessed = 0
        for file in files:
            directory = argv[0] + "/exp/" + file
            with open(directory) as input:
                if (".s" not in file): return
                subprocess.run(["gcc -o temp", argv[0] + "/src/" + file], stderr=subprocess.PIPE) # change this to match the ARM assembler instruction
                result = subprocess.run(["./temp 1111"], stderr=subprocess.PIPE).stderr.decode('utf-8').splitlines()
                temp = input.readline(); iterator = 0; diffFlag = False
                while temp:
                    if (temp != result[iterator]): 
                        diffFlag = True
                        break
                    temp = input.readline()
                    iterator += 1

                if diffFlag:
                    print(f"FAIL: {directory} on line {iterator + 1}"),
                    print(f"\texpected: {temp}")
                    print(f"\tgiven: {result[iterator]}")
                
                filesAssessed += 1
        score = score / filesAssessed
        print("-----------------------")
        print(f"Overall Score: {score}")

if __name__ == "__main__":
    main(sys.argv[1:])