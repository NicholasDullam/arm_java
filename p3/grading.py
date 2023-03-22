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
            firstLine = f.readline().replace('\n', '').strip('//').strip().lower()
            result = subprocess.run(["./parser", directory], stderr=subprocess.PIPE).stderr.decode('utf-8').replace('\n', '').lower()
            if (result == firstLine): score += 100
            else: 
                print(f"FAIL: {directory}"),
                print(f"\texpected: {result}")
                print(f"\tgiven: {firstLine}")
    score = score / len(files)
    print("-----------------------")
    print(f"Overall Score: {score}")

if __name__ == "__main__":
    main(sys.argv[1:])