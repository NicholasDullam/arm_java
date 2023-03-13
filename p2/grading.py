#!/usr/bin/env python3
import os
import sys
import subprocess

def main(argv):
    if (not len(argv)): return
    files = os.listdir(argv[0]); score = 0
    for file in files:
        directory = argv[0] + "/" + file
        with open(directory) as f:
            firstLine = f.readline().strip('\n').strip('//').strip().lower()
            result = subprocess.run(["./parser", directory], stderr=subprocess.PIPE).stderr.decode('utf-8').strip('\n').lower()
            if (result == firstLine): score += 100
            else: print(f"FAIL: {directory}\n", "expected: " + firstLine + '\n', "given: " + result)
    score = score / len(files)
    print("--------")
    print(f"Overall Score: {score}")
    
if __name__ == "__main__":
    main(sys.argv[1:])