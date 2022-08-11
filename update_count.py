import os
import re
from path import *

def count_problems():
    cnt = 0
    search_path = Path.SOL
    for root, dir, files in os.walk(search_path):
        for i in files:
            cnt += (i.endswith(".md"))
    return cnt


def update_count(cnt):
    readme = Path.README
    with open(readme, "r+") as f:
        contents = f.read()
        pattern = re.compile(r"Problems Count : [0-9]*",0)
        contents = pattern.sub(f"Problems Count : {cnt}",contents)
        f.seek(0)
        f.truncate()
        f.write(contents)
            

def main():
    update_count(count_problems())

if __name__ == "__main__":
    main()
