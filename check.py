import sys
n = int(sys.argv[1])
negative = False
if n<0:                 #saves if the number is negative or positive
    negative = True

strN = str(n).replace("-", "")     #removes eventual negative sign

total = 0
for x in strN:                 #calculates the munchausen number
    x=int(x)
    if negative: x*=-1
    total+=x**abs(x)
    
if (total == n):
    print("The number is a Munchausen number!")
else:
    print("The number is NOT Munchausen number!")
    
total = 0
for x in strN:                 #does the same thing again but with 0^0 = 0
    x=int(x)
    if (x!=0):
        if negative: x*=-1
        total+=x**abs(x)
    
if (total == n):
    print("The number is a Munchausen number! (if 0^0 = 0)")