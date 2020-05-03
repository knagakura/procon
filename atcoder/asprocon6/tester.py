
import os

txt_name = input()

# compile
os.system("g++-9 {}".format("a.cpp"))

# inputを入れてoutputをもらう
input_path = "sample/practice/{}.txt".format(txt_name)
out_path =   "sample/practice/output/{}.out.txt".format(txt_name)
print(input_path)

print(out_path)
os.system("./a.out < {} > {}".format(input_path, out_path))
# input と outputのpathをcheckerに渡して点数を表示する
os.system("g++-9 ./sample/output_checker.cpp -o b.out")
os.system("./b.out {} {} null".format(input_path, out_path))
