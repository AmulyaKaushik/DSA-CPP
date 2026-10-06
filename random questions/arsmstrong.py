n = 153
temp = n
power = 0
while temp > 0 :
    power += 1
    temp //= 10
temp = n
sum = 0
print(f"Power = {power}")
while temp > 0:
    digit = temp%10
    sum += digit**power
    temp //= 10
print(f"Sum = {sum}")
if(n == sum):
    print(f"{n} is an Armstrong Number")
else:
    print(f"{n} is not an Armstrong Number")

# print(153/10)
# print(153//10)