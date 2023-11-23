echo "Enter Principal Amount:"
read p
echo "Enter number of years:"
read n
echo "Enter rate of Interest:"
read r
si=`expr "scale=2; $p * $n * $r / 100" | bc`
echo "Simple Interest : $si"
