// Print number for 1 to 5 using for loop
#!/bin/bash

for i in 1 2 3 4 5
do
  echo $i
done

//Using while loop
#!/bin/bash

i=1
while [ $i -le 5 ]
do
  echo $i
  i=$((i+1))
done

//Using until loop
#!/bin/bash

i=1
until [ $i -gt 5 ]
do
  echo $i
  i=$((i+1))
done

//Sum of first n numbers
#!/bin/bash

echo "Enter a number:"
read n

i=1
sum=0

while [ $i -le $n ]
do
  sum=$((sum + i))
  i=$((i + 1))
done

echo "Sum of first $n numbers is: $sum"



//Multiplication Table (Using for)
#!/bin/bash

echo "Enter a number:"
read n

for i in {1..10}
do
  echo "$n x $i = $((n * i))"
done

//Prime number using while loop
#!/bin/bash

echo "Enter a number:"
read n

i=2
flag=0

while [ $i -lt $n ]
do
  if [ $((n % i)) -eq 0 ]
  then
    flag=1
    break
  fi
  i=$((i + 1))
done

if [ $n -le 1 ]
then
  echo "$n is NOT a Prime number"
elif [ $flag -eq 0 ]
then
  echo "$n is a Prime number"
else
  echo "$n is NOT a Prime number"
fi

//Factorial using while loop
#!/bin/bash

echo "Enter a number:"
read n

fact=1
i=1

while [ $i -le $n ]
do
  fact=$((fact * i))
  i=$((i + 1))
done

echo "Factorial of $n is: $fact"

