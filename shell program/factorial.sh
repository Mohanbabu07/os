echo "Enter Number"
read n
fact=1
count=1
while [ $count -le $n ]
do
  fact=$((fact * count))
  count=$((count + 1))
done
echo "Factorial of $n is $fact"
