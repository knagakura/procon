python3 ./tester/generator.py 1245 > input.txt
./a.out < input.txt > output.txt
python3 ./tester/tester.py input.txt output.txt
open -a "Google Chrome" tester/vis.html
