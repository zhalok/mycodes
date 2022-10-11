input_file = open("input.txt", "r")
testcase = input_file.read()
testcase = testcase[1:len(testcase)-1].split((","))
testcase_size = len(testcase)
vals = ""
vals += str(testcase_size)
vals += "\n"
for i in testcase:
    vals += i
    vals += " "

output_file = open("input.txt", "w")
output_file.write(vals)
