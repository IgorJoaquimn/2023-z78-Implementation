import sys
import os
path = "arquivos_de_teste/"
exe = "./bin/tp1.out"
out = ".z78"
for file in os.listdir(path):
    if(file.endswith(out) or file.endswith('2')):
        os.system(f"rm {path+file}")
        continue
    try:
        arq = path+file
        # os.system(f"{exe} -c {arq}")
        # os.system(f"{exe} -x {arq[0:len(arq) - 4]}.z78 {arq}2")
        # os.system(f"diff {arq} {arq}2")

    except Exception as e:
        print("Error in: " + path+file)
        with open(path+file, "r") as f:
            for line in f.readlines():
                print(line[:-1])
        raise e
